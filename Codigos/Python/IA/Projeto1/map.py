import folium
import json
import pandas as pd 
import os

br_estados = 'br_states.json'
geo_json_data = json.load(open(br_estados))

mapa = folium.Map(
    width=600, height=600,
    location=[-15.77972, -55], 
    zoom_start=4
)

folium.GeoJson(
    geo_json_data,
    style_function=lambda feature: {
        'fillColor': 'white',
        'color': 'black',
        'weight': 0.5,
    }
).add_to(mapa)


"""mapa.choropleth(
    geo_data=br_estados,
    name='cloropleth',
    data=geo_json_data,
    fill_opacity=0.7,
    line_opacity=0.2
)

folium.LayerControl().add_to(mapa)"""
mapa.save('map.html')
mapa