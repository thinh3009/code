from opencage.geocoder import OpenCageGeocode
from pprint import pprint

key = '43586076b60a425fa59e4fa5e35062da'
geocoder = OpenCageGeocode(key)

results = geocoder.reverse_geocode(10.8326, 106.6581)
pprint(results)