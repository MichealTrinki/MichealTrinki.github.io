let weather = {
    apiKey:"56da3488969188a57db799aa2dd58809",

fetchWeather: function (city) {
    fetch(
    "https://api.openweathermap.org/data/2.5/weather?q=" 
    + city 
    + "&units=metric&appid="
    + this.apiKey
    )
    .then((response) => response.json())
    .then((data) => this.displayWeather(data));

},
 displayWeather: function(data) 
 { const { name } = data;
   const { icon, description} = data.weather[0];
   const { temp, humidity} = data.main;
   const { speed } = data.wind;
   console.log(name,icon,description,temp,humidity,speed)
   document.querySelector(".city").innerText = "weather in " + name;
   document.querySelector(".icon").src = "https://openweathermap.org/img/wn/" + icon + ".png";
   document.querySelector(".description").innerText = description;
   document.querySelector(".temp").innerText = temp + "°C";
   document.querySelector(".humidity").innerText = "humidity: " + humidity + "%";
   document.querySelector(".wind").innerText = "wind speed: " + speed + "km/h";
   document.querySelector(".weather").classList.remove("loading");
   document.body.style.backgroundImage = "url('https://source.unsplash.com/1600x900/?" + name + "');"

 },

 search: function(){
    this.fetchWeather(document.querySelector(".search-bar").value)
},
};
document.querySelector(".search button").addEventListener("click", function() {
    weather.search();

});

document.querySelector(".search-bar").addEventListener("keyup", function (event) {
    if(event.key == "Enter") {
        weather.search();
    }

});
weather.fetchWeather("London");