# Please install OpenAI SDK first: `pip3 install openai`

from openai import OpenAI

client = OpenAI(api_key="sk-8bcf6965788b43ad9863be0184353e78", base_url="https://api.deepseek.com")

response = client.chat.completions.create(
    model="deepseek-chat",
    messages=[
        {"role": "system", "content": "You are a helpful assistant"},
        {"role": "user", "content": "mô tả những món ăn ưa thích của nó"},
    ],
    stream=True
)

# Iterate through the stream of events
for chunk in response:
    # Check if the chunk contains a 'choices' key
    if hasattr(chunk, "choices") and len(chunk.choices) > 0 and hasattr(chunk.choices[0], "delta") and hasattr(chunk.choices[0].delta, "content"):
        # Print the content of the message
        print(chunk.choices[0].delta.content, end="", flush=True)