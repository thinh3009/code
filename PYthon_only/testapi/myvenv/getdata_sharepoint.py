from office365.runtime.auth.client_credential import ClientCredential
from office365.sharepoint.client_context import ClientContext

# Thông tin kết nối
site_url = "https://tencongty.sharepoint.com/sites/tensite"
client_id = "client_id_app_register"
client_secret = "client_secret_app_register"
list_name = "TenListSharePoint"

# Tạo kết nối
credentials = ClientCredential(client_id, client_secret)
ctx = ClientContext(site_url).with_credentials(credentials)

# Lấy danh sách
sp_list = ctx.web.lists.get_by_title(list_name)
items = sp_list.items.get().execute_query()

# In kết quả
for item in items:
    print(f"Title: {item.properties.get('Title')}, ID: {item.properties.get('ID')}")
