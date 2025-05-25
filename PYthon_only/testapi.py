# conn = http.client.HTTPSConnection("v3.football.api-sports.io")

# headers = {
#     'x-rapidapi-host': "v3.football.api-sports.io",
#     'x-rapidapi-key': "71ca0c09b748389847c49c3284c1233f"
#     }

# conn.request("GET", "/leagues", headers=headers)

# res = conn.getresponse()
# data = res.read()

# print(data.decode("utf-8"))

import requests
import pandas as pd
import json
from random import randint
url = "https://v3.football.api-sports.io/coachs"
def range_of_num():
    return randint(1,100)
payload = {
    'team':f'{range_of_num()}'
}
headers = {
    'x-rapidapi-key': '71ca0c09b748389847c49c3284c1233f',
    'x-rapidapi-host': 'v3.football.api-sports.io'
}

response = requests.request("GET", url, headers=headers, params=payload)
print(response.text)
# Parse JSON response
# data = json.loads(response.text)

# # Convert to DataFrame
# # Assuming 'response' is the key containing the data array in the API response
# df = pd.DataFrame(data['response'])

# # Export to Excel
# df.to_excel('coaches_data.xlsx', index=False)

# print('Data successfully exported to coaches_data.xlsx')

