import streamlit as st
from phonenumbers import geocoder
from phonenumbers import carrier
import phonenumbers

def main():
    st.title("Phone number location tracking")
    st.subheader("build with python and streamlit")
    mobile_number=st.text_input("enter your phone: ",type="password")
    if st.button("Track"):
        ch_number=phonenumbers.parse(mobile_number,'CH')
        st.success("Country Name {}".format(geocoder.description_for_number(ch_number, "en")))
        services_operator=phonenumbers.parse(mobile_number,"RO")
        st.success("Service Operator: {}".format(carrier.name_for_number(services_operator, 'en')))
        

if __name__=="__main__":
    main()    