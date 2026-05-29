from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import TimeoutException, NoSuchElementException
import time
import os
import tkinter as tk
from tkinter import ttk, messagebox, filedialog
import threading
import json


class FacebookMessenger:
    def __init__(self):
        """Initialize the Facebook Messenger automation"""
        self.driver = None
        self.wait = None
        self.is_signed_in = False

    def setup_driver(self):
        """Setup Chrome driver with options"""
        options = webdriver.ChromeOptions()
        options.add_argument("--disable-notifications")
        options.add_argument("--disable-popup-blocking")
        options.add_argument("--start-maximized")
        # Keep browser open for debugging
        options.add_experimental_option("detach", True)
        # Persist login session across app restarts
        profile_dir = os.path.join(os.path.expanduser("~"), ".chrome_fb_messenger_profile")
        options.add_argument(f"--user-data-dir={profile_dir}")

        self.driver = webdriver.Chrome(options=options)
        self.wait = WebDriverWait(self.driver, 20)

    def check_logged_in(self):
        """Check if already logged in to Facebook"""
        try:
            self.driver.get("https://www.facebook.com")
            time.sleep(2)
            current_url = self.driver.current_url
            if "login" not in current_url and "checkpoint" not in current_url:
                # Try to find an element that only exists when logged in
                try:
                    self.driver.find_element(By.XPATH, "//div[@aria-label='Facebook'] | //a[@aria-label='Home']")
                    return True
                except NoSuchElementException:
                    pass
                # Fallback: if URL is facebook.com without login redirect, assume logged in
                if "facebook.com" in current_url and "login" not in current_url:
                    return True
            return False
        except Exception:
            return False

    def sign_in_facebook(self, email, password):
        """
        Auto sign in to Facebook. Skips login if already signed in.

        Args:
            email (str): Facebook email or phone number
            password (str): Facebook password
        """
        try:
            # Skip login if already signed in this session
            if self.is_signed_in:
                print("Already signed in, skipping login.")
                return True

            # Check if saved session is still valid
            print("Checking existing session...")
            if self.check_logged_in():
                print("Session restored — no need to log in again.")
                self.is_signed_in = True
                return True

            print("Opening Facebook login...")
            self.driver.get("https://www.facebook.com")
            time.sleep(2)

            # Find and fill email field
            print("Entering email...")
            email_field = self.wait.until(
                EC.presence_of_element_located((By.ID, "email"))
            )
            email_field.clear()
            email_field.send_keys(email)

            # Find and fill password field
            print("Entering password...")
            password_field = self.driver.find_element(By.ID, "pass")
            password_field.clear()
            password_field.send_keys(password)

            # Click login button
            print("Clicking login button...")
            login_button = self.driver.find_element(By.NAME, "login")
            login_button.click()

            # Wait for login to complete
            time.sleep(5)

            # Check if login was successful
            if "login" in self.driver.current_url:
                print("Login failed! Please check your credentials.")
                return False

            print("Login successful!")
            self.is_signed_in = True
            return True

        except TimeoutException:
            print("Timeout: Could not find login elements")
            return False
        except Exception as e:
            print(f"Error during login: {str(e)}")
            return False

    def open_messenger(self, recipient_name):
        """
        Open Messenger and search for a recipient

        Args:
            recipient_name (str): Name of the person to chat with
        """
        try:
            print(f"Opening Messenger and searching for {recipient_name}...")
            self.driver.get("https://www.facebook.com/messages")
            time.sleep(3)

            # Search for recipient
            search_box = self.wait.until(
                EC.presence_of_element_located((By.XPATH, "//input[@placeholder='Search Messenger' or @aria-label='Search Messenger']"))
            )
            search_box.click()
            search_box.send_keys(recipient_name)
            time.sleep(2)

            # Click on first search result
            print("Selecting recipient...")
            first_result = self.wait.until(
                EC.element_to_be_clickable((By.XPATH, "//div[@role='listitem'][1]"))
            )
            first_result.click()
            time.sleep(2)

            print(f"Chat with {recipient_name} opened successfully!")
            return True

        except Exception as e:
            print(f"Error opening messenger: {str(e)}")
            return False

    def send_message(self, message):
        """
        Send a message in the current chat

        Args:
            message (str): Message text to send
        """
        try:
            print(f"Sending message: {message}")

            # Find message input box - multiple possible selectors
            message_box = None
            selectors = [
                (By.XPATH, "//div[@role='textbox' and @contenteditable='true']"),
                (By.XPATH, "//div[@aria-label='Message']"),
                (By.XPATH, "//div[contains(@aria-label, 'Message')]")
            ]

            for selector in selectors:
                try:
                    message_box = self.wait.until(
                        EC.presence_of_element_located(selector)
                    )
                    break
                except:
                    continue

            if not message_box:
                print("Could not find message input box")
                return False

            # Type message
            message_box.click()
            time.sleep(0.5)
            message_box.send_keys(message)
            time.sleep(0.5)

            # Send message with Enter key
            message_box.send_keys(Keys.ENTER)
            time.sleep(1)

            print("Message sent successfully!")
            return True

        except Exception as e:
            print(f"Error sending message: {str(e)}")
            return False

    def attach_image(self, image_path):
        """
        Attach and send an image in the current chat

        Args:
            image_path (str): Full path to the image file
        """
        try:
            # Verify image exists
            if not os.path.exists(image_path):
                print(f"Error: Image file not found at {image_path}")
                return False

            print(f"Attaching image: {image_path}")

            # Find and click the attachment button
            attachment_selectors = [
                (By.XPATH, "//input[@type='file' and @accept='image/*,image/heif,image/heic,video/*,video/mp4,video/x-m4v,video/x-matroska,.mkv']"),
                (By.XPATH, "//input[@type='file']"),
                (By.XPATH, "//input[@accept='image/*']")
            ]

            file_input = None
            for selector in attachment_selectors:
                try:
                    file_input = self.driver.find_element(*selector)
                    break
                except:
                    continue

            if not file_input:
                print("Could not find file input element")
                return False

            # Send the file path to the input element
            file_input.send_keys(image_path)
            time.sleep(2)

            # Wait for image to upload and then send
            print("Waiting for image to upload...")
            time.sleep(3)

            # Press Enter to send (or find Send button)
            try:
                send_button = self.driver.find_element(By.XPATH, "//div[@aria-label='Press enter to send']")
                send_button.click()
            except:
                # Alternative: use Enter key
                file_input.send_keys(Keys.ENTER)

            time.sleep(2)
            print("Image sent successfully!")
            return True

        except Exception as e:
            print(f"Error attaching image: {str(e)}")
            return False

    def close(self):
        """Close the browser"""
        if self.driver:
            self.driver.quit()
            print("Browser closed.")


class FacebookMessengerGUI:
    def __init__(self, root):
        """Initialize the GUI"""
        self.root = root
        self.root.title("Facebook Messenger Auto Sender")
        self.root.geometry("600x700")
        self.root.resizable(False, False)

        self.messenger = FacebookMessenger()
        self.image_path = ""
        self.persons_file = "persons_list.json"
        self.persons_list = self.load_persons()

        self.setup_gui()

    def load_persons(self):
        """Load persons list from file"""
        if os.path.exists(self.persons_file):
            try:
                with open(self.persons_file, 'r', encoding='utf-8') as f:
                    return json.load(f)
            except:
                return []
        return []

    def save_persons(self):
        """Save persons list to file"""
        try:
            with open(self.persons_file, 'w', encoding='utf-8') as f:
                json.dump(self.persons_list, f, ensure_ascii=False, indent=2)
        except Exception as e:
            print(f"Error saving persons: {e}")

    def setup_gui(self):
        """Setup the GUI components"""
        # Main frame
        main_frame = ttk.Frame(self.root, padding="10")
        main_frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))

        # Title
        title_label = ttk.Label(main_frame, text="Facebook Messenger Auto Sender",
                               font=("Arial", 16, "bold"))
        title_label.grid(row=0, column=0, columnspan=2, pady=10)

        # Facebook Login Section
        login_frame = ttk.LabelFrame(main_frame, text="Facebook Login", padding="10")
        login_frame.grid(row=1, column=0, columnspan=2, sticky=(tk.W, tk.E), pady=5)

        ttk.Label(login_frame, text="Email/Phone:").grid(row=0, column=0, sticky=tk.W, pady=5)
        self.email_entry = ttk.Entry(login_frame, width=40)
        self.email_entry.grid(row=0, column=1, pady=5, padx=5)

        ttk.Label(login_frame, text="Password:").grid(row=1, column=0, sticky=tk.W, pady=5)
        self.password_entry = ttk.Entry(login_frame, width=40, show="*")
        self.password_entry.grid(row=1, column=1, pady=5, padx=5)

        # Person Selection Section
        person_frame = ttk.LabelFrame(main_frame, text="Select/Add Person", padding="10")
        person_frame.grid(row=2, column=0, columnspan=2, sticky=(tk.W, tk.E), pady=5)

        ttk.Label(person_frame, text="Select Person:").grid(row=0, column=0, sticky=tk.W, pady=5)
        self.person_combobox = ttk.Combobox(person_frame, width=30, values=self.persons_list)
        self.person_combobox.grid(row=0, column=1, pady=5, padx=5)
        if self.persons_list:
            self.person_combobox.current(0)

        # Add person section
        ttk.Label(person_frame, text="Add New Person:").grid(row=1, column=0, sticky=tk.W, pady=5)
        self.new_person_entry = ttk.Entry(person_frame, width=30)
        self.new_person_entry.grid(row=1, column=1, pady=5, padx=5)

        add_person_btn = ttk.Button(person_frame, text="Add Person",
                                    command=self.add_person)
        add_person_btn.grid(row=1, column=2, pady=5, padx=5)

        remove_person_btn = ttk.Button(person_frame, text="Remove Selected",
                                       command=self.remove_person)
        remove_person_btn.grid(row=0, column=2, pady=5, padx=5)

        # Message Section
        message_frame = ttk.LabelFrame(main_frame, text="Message", padding="10")
        message_frame.grid(row=3, column=0, columnspan=2, sticky=(tk.W, tk.E), pady=5)

        ttk.Label(message_frame, text="Chat Text:").grid(row=0, column=0, sticky=tk.NW, pady=5)

        # Text widget with scrollbar
        text_scroll = ttk.Scrollbar(message_frame)
        text_scroll.grid(row=1, column=1, sticky=(tk.N, tk.S))

        self.message_text = tk.Text(message_frame, width=50, height=8,
                                    yscrollcommand=text_scroll.set)
        self.message_text.grid(row=1, column=0, pady=5)
        text_scroll.config(command=self.message_text.yview)

        # Image Section
        image_frame = ttk.LabelFrame(main_frame, text="Image (Optional)", padding="10")
        image_frame.grid(row=4, column=0, columnspan=2, sticky=(tk.W, tk.E), pady=5)

        ttk.Label(image_frame, text="Image Path:").grid(row=0, column=0, sticky=tk.W, pady=5)
        self.image_path_label = ttk.Label(image_frame, text="No image selected",
                                          foreground="gray", width=35, anchor=tk.W)
        self.image_path_label.grid(row=0, column=1, pady=5, padx=5)

        browse_btn = ttk.Button(image_frame, text="Browse Image",
                               command=self.browse_image)
        browse_btn.grid(row=0, column=2, pady=5, padx=5)

        clear_image_btn = ttk.Button(image_frame, text="Clear",
                                     command=self.clear_image)
        clear_image_btn.grid(row=1, column=2, pady=5, padx=5)

        # Send Button
        self.send_btn = ttk.Button(main_frame, text="Send Message",
                                   command=self.send_message_thread,
                                   style="Accent.TButton")
        self.send_btn.grid(row=5, column=0, columnspan=2, pady=20)

        # Status Section
        status_frame = ttk.LabelFrame(main_frame, text="Status", padding="10")
        status_frame.grid(row=6, column=0, columnspan=2, sticky=(tk.W, tk.E), pady=5)

        status_scroll = ttk.Scrollbar(status_frame)
        status_scroll.pack(side=tk.RIGHT, fill=tk.Y)

        self.status_text = tk.Text(status_frame, width=60, height=8,
                                   yscrollcommand=status_scroll.set, state=tk.DISABLED)
        self.status_text.pack(side=tk.LEFT, fill=tk.BOTH)
        status_scroll.config(command=self.status_text.yview)

    def add_person(self):
        """Add a new person to the list"""
        new_person = self.new_person_entry.get().strip()
        if new_person:
            if new_person not in self.persons_list:
                self.persons_list.append(new_person)
                self.person_combobox['values'] = self.persons_list
                self.person_combobox.set(new_person)
                self.new_person_entry.delete(0, tk.END)
                self.save_persons()
                self.update_status(f"Added '{new_person}' to the list")
            else:
                messagebox.showwarning("Duplicate", "This person is already in the list")
        else:
            messagebox.showwarning("Empty Field", "Please enter a person's name")

    def remove_person(self):
        """Remove selected person from the list"""
        selected = self.person_combobox.get()
        if selected and selected in self.persons_list:
            if messagebox.askyesno("Confirm", f"Remove '{selected}' from the list?"):
                self.persons_list.remove(selected)
                self.person_combobox['values'] = self.persons_list
                if self.persons_list:
                    self.person_combobox.current(0)
                else:
                    self.person_combobox.set('')
                self.save_persons()
                self.update_status(f"Removed '{selected}' from the list")

    def browse_image(self):
        """Open file dialog to select an image"""
        file_path = filedialog.askopenfilename(
            title="Select an Image",
            filetypes=[("Image Files", "*.png *.jpg *.jpeg *.gif *.bmp"),
                      ("All Files", "*.*")]
        )
        if file_path:
            self.image_path = file_path
            # Show only filename in label
            filename = os.path.basename(file_path)
            self.image_path_label.config(text=filename, foreground="black")
            self.update_status(f"Image selected: {filename}")

    def clear_image(self):
        """Clear selected image"""
        self.image_path = ""
        self.image_path_label.config(text="No image selected", foreground="gray")
        self.update_status("Image cleared")

    def update_status(self, message):
        """Update the status text box"""
        self.status_text.config(state=tk.NORMAL)
        self.status_text.insert(tk.END, f"{message}\n")
        self.status_text.see(tk.END)
        self.status_text.config(state=tk.DISABLED)
        print(message)

    def send_message_thread(self):
        """Start send message in a separate thread"""
        thread = threading.Thread(target=self.send_message, daemon=True)
        thread.start()

    def send_message(self):
        """Send message using Selenium"""
        # Disable send button
        self.send_btn.config(state=tk.DISABLED)

        try:
            # Validate inputs
            email = self.email_entry.get().strip()
            password = self.password_entry.get().strip()
            person = self.person_combobox.get().strip()
            message = self.message_text.get("1.0", tk.END).strip()

            if not self.messenger.is_signed_in and (not email or not password):
                messagebox.showerror("Error", "Please enter email and password")
                return

            if not person:
                messagebox.showerror("Error", "Please select or add a person")
                return

            if not message and not self.image_path:
                messagebox.showerror("Error", "Please enter a message or select an image")
                return

            # Setup driver if not already set up
            if not self.messenger.driver:
                self.update_status("Setting up Chrome driver...")
                self.messenger.setup_driver()

            # Sign in to Facebook
            self.update_status("Signing in to Facebook...")
            if not self.messenger.sign_in_facebook(email, password):
                messagebox.showerror("Error", "Failed to sign in to Facebook")
                return

            # Open messenger with recipient
            self.update_status(f"Opening chat with {person}...")
            if not self.messenger.open_messenger(person):
                messagebox.showerror("Error", f"Failed to open chat with {person}")
                return

            # Send message if provided
            if message:
                self.update_status("Sending message...")
                if self.messenger.send_message(message):
                    self.update_status("Message sent successfully!")
                else:
                    messagebox.showerror("Error", "Failed to send message")
                    return

            # Send image if provided
            if self.image_path:
                self.update_status("Sending image...")
                time.sleep(1)
                if self.messenger.attach_image(self.image_path):
                    self.update_status("Image sent successfully!")
                else:
                    messagebox.showerror("Error", "Failed to send image")
                    return

            self.update_status("All messages sent successfully!")
            messagebox.showinfo("Success", "Message sent successfully!")

        except Exception as e:
            error_msg = f"An error occurred: {str(e)}"
            self.update_status(error_msg)
            messagebox.showerror("Error", error_msg)
        finally:
            # Re-enable send button
            self.send_btn.config(state=tk.NORMAL)


def main():
    """Main function to run the GUI"""
    root = tk.Tk()
    app = FacebookMessengerGUI(root)
    root.mainloop()


if __name__ == "__main__":
    main()
