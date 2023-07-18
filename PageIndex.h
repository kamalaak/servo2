    const char MAIN_page[] PROGMEM = R"=====(
    <!DOCTYPE html>
    <html>
      <head>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <style>
          html {
            font-family: Arial;
            display: inline-block;
            margin: 0px auto;
            text-align: center;
          }
          
          .slidecontainer {
            width: 100%;
          }

          .slider {
            -webkit-appearance: none;
            width: 50%;
            height: 15px;
            border-radius: 5px;
            background: #d3d3d3;
            outline: none;
            opacity: 0.7;
            -webkit-transition: .2s;
            transition: opacity .2s;
          }

          .slider:hover {
            opacity: 1;
          }

          .slider::-webkit-slider-thumb {
            -webkit-appearance: none;
            appearance: none;
            width: 25px;
            height: 25px;
            border-radius: 50%;
            background: #4CAF50;
            cursor: pointer;
          }

          .slider::-moz-range-thumb {
            width: 25px;
            height: 25px;
            border-radius: 50%;
            background: #4CAF50;
            cursor: pointer;
          }
        </style>
      </head>
      <body>
    <h1>NodeMCU ESP8266 / ESP12E Control Servo SG90</h1>
        <br><br>
        <div class="slidecontainer">
          <input type="range" min="0" max="180" value="50" class="slider" id="myRange1">
          <p>Value : <span id="demo1"></span></p>
        </div>
        <div class="slidecontainer">
          <input type="range" min="0" max="180" value="50" class="slider" id="myRange2">
          <p>Value : <span id="demo2"></span></p>
        </div>

        <script>
        function sendData(pos, servoNumber) {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          console.log(this.responseText);
        }
      };
      xhttp.open("GET", "setPOS?servoPOS=" + pos + "&servoNumber=" + servoNumber, true);
      xhttp.send();
    }
        var slider = document.getElementById("myRange1");
  var output = document.getElementById("demo1");
  output.innerHTML = slider.value;

  slider.oninput = function() {
    output.innerHTML = this.value;
    sendData(output.innerHTML, 1);
  }

  var slider2 = document.getElementById("myRange2");
  var output2 = document.getElementById("demo2");
  output2.innerHTML = slider2.value;

  slider2.oninput = function() {
    output2.innerHTML = this.value;
    sendData(output2.innerHTML, 2);
  }

          
        </script>

      </body>
    </html>
    )=====";
