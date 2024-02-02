import openpyxl as xl
wb=xl.load_workbook("C:\\Users\\buidu\\OneDrive\\Máy tính\\myCode\\code\\PYthon_only\\tu_vung.xlsx")
sheet=wb['Sheet1']
cell=sheet['a1']
cell=sheet.cell(1,1)
print(cell.value)