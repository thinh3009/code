import requests
from bs4 import BeautifulSoup
import pandas as pd
from openpyxl import load_workbook

index = 1

#the generic form of getting url
#def x():
    #x_res = requests.get('url')
    #x_soup = BeautifulSoup(x_res.text, 'lxml')
    
    #x_span = x_soup.find_all("span", class_= "sc-f70bb44c-0 jxpCgO base-text")
    #for x_get in x_span:
        #x_out = x_get.get_text()
        #x_str = x_out[index:]
        #x = float(x_str)       
        #print("X = ", x)

def Bitcoin():
    Btc_res = requests.get('https://coinmarketcap.com/currencies/bitcoin/')
    Btc_soup = BeautifulSoup(Btc_res.text, 'lxml')
    
    #Btc_element = Btc_soup.find_all("span", class_= "sc-f70bb44c-0 flfGQp flexStart alignBaseline")
    Btc_span = Btc_soup.find_all("span", class_= "sc-f70bb44c-0 jxpCgO base-text")
    for btc_get in Btc_span:
        btc_out = btc_get.get_text()
        btc_str = btc_out[index:]
        BTC = float((btc_str).replace(',',''))
        print("BTC= ",BTC)

def Ethereum():
    eth_res = requests.get('https://coinmarketcap.com/currencies/ethereum/')
    eth_soup = BeautifulSoup(eth_res.text, 'lxml')
    
    eth_span = eth_soup.find_all("span", class_= "sc-f70bb44c-0 jxpCgO base-text")
    for eth_get in eth_span:
        eth_out = eth_get.get_text()
        eth_str = eth_out[index:]
        ETH = float((eth_str).replace(',',''))       
        print("ETH = ", ETH)

#GET LINK DATA:
def ChainLink():
    Link_res = requests.get('https://coinmarketcap.com/currencies/chainlink/')
    Link_soup = BeautifulSoup(Link_res.text, 'lxml')

    #Link_elements = Link_soup.find_all("span", class_="sc-f70bb44c-0 flfGQp flexStart alignBaseline")
    Link_span = Link_soup.find_all("span", class_="sc-f70bb44c-0 jxpCgO base-text")
    for Link_get in Link_span:
        Link_out = Link_get.get_text()
        #print("Link = "+ Link.get_text())
        Link_str= Link_out[index:]
        Link = float(Link_str)
        print("LINK= ",Link)

#GET DOT DATA
def Polkadot():
    Dot_res = requests.get('https://coinmarketcap.com/currencies/polkadot-new/')
    Dot_soup = BeautifulSoup(Dot_res.text, 'lxml')

    #Dot_elements = Dot_soup.find_all("span", class_= "sc-f70bb44c-0 flfGQp flexStart alignBaseline")
    Dot_span = Dot_soup.find_all("span", class_= "sc-f70bb44c-0 jxpCgO base-text")
    for Dot_get in Dot_span:
        Dot_out = Dot_get.get_text()
        #print("Dot= " + Dot.get_text())
        #Dot_text = Dot.get_text()
        Dot_str= Dot_out[index:]
        Dot = float(Dot_str)
        print("DOT= ",Dot)


#GET ADA DATA: 
def Cardano():
    ADA_res = requests.get('https://coinmarketcap.com/currencies/cardano/')
    ADA_soup = BeautifulSoup(ADA_res.text, 'lxml')
    
    #ADA_element = ADA_soup.find_all("span", class_= "sc-f70bb44c-0 flfGQp flexStart alignBaseline")
    ADA_span = ADA_soup.find_all("span", class_= "sc-f70bb44c-0 jxpCgO base-text")
    for ADA_get in ADA_span:
        ADA_out = ADA_get.get_text()
        ADA_str = ADA_out[index:]
        ADA = float(ADA_str)
        print("ADA = ", ADA)


def Sui():
    Sui_res = requests.get('https://coinmarketcap.com/currencies/sui/')
    Sui_soup = BeautifulSoup(Sui_res.text, 'lxml')
    
    #Sui_element = x_soup.find_all("span", class_= "sc-f70bb44c-0 flfGQp flexStart alignBaseline")
    Sui_span = Sui_soup.find_all("span", class_= "sc-f70bb44c-0 jxpCgO base-text")
    for Sui_get in Sui_span:
        Sui_out = Sui_get.get_text()
        Sui_str = Sui_out[index:]
        SUI = float(Sui_str)
        print("SUI = ", SUI)

def TheGraph():
    Grt_res = requests.get('https://coinmarketcap.com/currencies/the-graph/')
    Grt_soup = BeautifulSoup(Grt_res.text, 'lxml')
    
    Grt_span = Grt_soup.find_all("span", class_= "sc-f70bb44c-0 jxpCgO base-text")
    for Grt_get in Grt_span:
        Grt_out = Grt_get.get_text()
        Grt_str = Grt_out[index:]
        GRT = float(Grt_str)
        print("GRT = ", GRT)


#GET data from Excel
excel_path = "C:/Users/PC/Desktop/ThongKeCrypto.xlsx"
#Load the workbook
workbook = load_workbook(excel_path)

#Select the worksheet (by name)
worksheet = workbook["Price"]

#Access a specific cell
cell_Link = workbook["L10"].value

Print("Link in excel= ", cell_Link)
workbook.close()

Bitcoin()
Ethereum()
ChainLink()
Polkadot()
Cardano()
Sui()
TheGraph()