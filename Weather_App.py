import requests
from bs4 import BeautifulSoup

def get_weather(city):
    url = f"https://www.weather.com/weather/today/l/{city}"
    response = requests.get(url)
    soup = BeautifulSoup(response.text, "html.parser")
    
    temperature = soup.find("span", class_="CurrentConditions--tempValue--3KcTQ").text
    description = soup.find("div", class_="CurrentConditions--phraseValue--2xXSr").text
    
    print(f"Weather in {city}:")
    print(f"Temperature: {temperature}")
    print(f"Description: {description}")

city = input("Enter the city name (e.g., New York, US): ")
get_weather(city)
