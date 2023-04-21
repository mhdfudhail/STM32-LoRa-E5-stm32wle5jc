from flask import Flask, render_template
import folium
import serialCollector_1
from time import sleep
from math import sin, cos, sqrt, atan2, radians

R = 6373.0

app = Flask(__name__)
print("----Receiver connected----")
###########--Get-Data--#############
def get_data():
    # print("checking...")
    iData,bt = serialCollector_1.collectData()
    print(iData,bt)
    return iData[1], iData[2], bt[0], bt[1]

@app.route('/')
def index():
    global bLat,bLon,iLat,iLon
    iLat,iLon,bLat,bLon = get_data()
#     distance = getDistance(node=(iLat,iLon),bt=(bLat,bLon))
#     print(distance)
#     colour = checkBoundary(distance)
#     print(bLat,",",bLon)

    folium_map = folium.Map(location=(bLat,bLon),zoom_start=16)

    folium.Circle(location= (bLat,bLon),radius=40).add_to(folium_map)
    folium.Marker(location= (iLat,iLon),popup="Timberline Lodge",icon=folium.Icon(color=colour)).add_to(folium_map)
    print("loading...")

    g = folium.GeoJson('world.json', name="geojson").add_to(folium_map)
    folium.GeoJsonTooltip(fields=["name"]).add_to(g)

    folium_map.save('templates/map.html')
    return render_template('index.html')

@app.route('/map')
def map():
    return render_template('map.html')

if __name__ == '__main__':
    app.run(debug=True)

