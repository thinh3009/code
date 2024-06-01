import phonenumbers
import folium 
from Mynumber import number

from phonenumbers import geocoder

Key= "43586076b60a425fa59e4fa5e35062da"
thinhNumber = phonenumbers.parse(number)

yourlocation = geocoder.description_for_number(thinhNumber, 'en')
print(yourlocation)

#get service provide

from phonenumbers import carrier

service_provide=phonenumbers.parse(number)
print(carrier.name_for_number(service_provide, 'en'))

from opencage.geocoder import OpenCageGeocode

geocoder = OpenCageGeocode(Key)

query=str(yourlocation)
results=geocoder.geocode(query)
print(results)

lat=results[0]['geometry']['lat']
lng=results[0]['geometry']['lng']
print(lat,lng)


myMapp = folium.Map(location=[lat,lng],zoom_start=9)
folium.Marker([lat,lng],popup=yourlocation).add_to((myMapp))
#save map in html
myMapp.save('myLocation.html')