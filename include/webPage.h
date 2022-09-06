#include <arduino.h>

const char index_html[] PROGMEM =  "<html lang=' '>\n\
    <head>\n\
      <meta charset='utf-8'>\n\
      <meta\n\
      name='viewport'\n\
      content='width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=0'\n\
      />\n\
      <title>Photodynamic Test</title>\n\
      <link rel='stylesheet' href='https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css' integrity='sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh' crossorigin='anonymous'>\n\
      <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js'></script>\n\
      <style>\n\
        header{background:#2C3E50;color:#FFF;top:0;position:fixed;z-index:2;width:100%;}\n\
        .title{margin-top:10px;margin-bottom:10px;display:inline-block;font-size:120px;}\n\
        .main{background: #FFF;}\n\
        .disclaimer{width:100%;left:169px;top:100px;position:absolute;}\n\
        .cardBox{box-shadow: 0 4px 8px 0 rgb(0 0 0 / 20%); transition: 0.3s;}\n\
        .cardBox:hover { box-shadow: 0 8px 16px 0 rgba(0,0,0,0.2);}\n\
        .buttomShadow{box-shadow: 0 3px 6px 0 rgb(0 0 0 / 20%); transition: 0.3s;}\n\
        .buttomShadow:hover{box-shadow: 0 4px 8px 0 rgba(0,0,0,0.2);}\n\
        .button-start-test-container{display:inline-block;}\n\
        .button-start-container{width:50%;margin-left:25%;margin-right:25%;}\n\
        .button-default{font-size:40px;color:white;display:inline;border-radius:20px;border:#F2F2F2;font-size:30px;margin-bottom:13px;padding:6px100px;background:#279090;margin-left:10%;margin-right:10%;width:80%;}\n\
        .button-start{font-size:40px;color:white;display:inline;border-radius:20px;border:#F2F2F2;font-size:30px;margin-bottom:13px;padding:6px 100px;background:#E84035;margin-left:10%;margin-right:10%;width:80%;}\n\
        .button-save {font-size: 30px;margin:0px;color:white;padding:6px100px;border-radius:20px;background:#2C3E50;border:#2C3E50;width:80%;margin-left:10%;margin-right:10%;margin-bottom:13px;}\n\
        .form-container{height:150px;width:80%;margin-right:10%;margin-left:10%;margin-bottom:30px;margin-top:0px;position:relative;}\n\
        .text{background:#F2F2F2;font-size:30px;}\n\
        .form-variable-control{width:100%;height:50px;margin-bottom:10px;border-radius:5px;font-size:30px;text-align:left;}\n\
        .card-style{width:590px;border-radius:20px;height:410px;margin:65px;margin-left:7%;margin-right:7%;}\n\
        .card-header-style{padding:0px;margin-bottom:13px;background-color:rgba(0,0,0,.03);solid rgba(0,0,0,.125);display:inline-block;}\n\
        .card-default-style{padding:0px;margin-bottom:13px;display:inline-block;background:#AFB3B0;}\n\
        .card-text{text-align:center;font-size:40px;font-weight:700;margin:0px;}\n\
        .cards-container{margin-left:6%;margin-right:0%;background:#FFF;}\n\
        .form-container {height:150px;width:80%;margin-right:10%;margin-left:10%;margin-bottom:30px;margin-top:0px;position:relative;}\n\
        .form-variable-control{margin-top:5px;width:100%;height:50px;margin-bottom:10px;border-radius:5px;font-size:30px;text-align:left;}\n\
        .form{background:#F2F2F2;}\n\
        .form-control{display:block;padding:.375rem .75rem;font-size:1rem;line-height: 1.5;color:#495057;background-color:#fff;background-clip:padding-box;border-radius:.25rem;transition:margin:0;position:absolute;margin-left:10%;margin-right:10%;width:80%;}\n\
        .form-variable-control-email{margin-top:5px;width:70%;height:50px;margin-bottom:10px;border-radius:5px;font-size:30px;text-align: left;}\n\
        .button-start-rows{font-size:30px;margin:0px;color:white;margin-top:13px;border-radius:20px;background:#1CA861;border:#2C3E50;width:100%;margin-bottom:13px;}\n\
        .button-start{font-size:30px;margin:0px;color:white;margin-top:13px;border-radius:20px;background:#C76E54;border:#2C3E50;width:100%;margin-bottom:13px;}\n\
        .checkbox-class{transform:scale(1.9);position:absolute;width:20px;right:20px;top:20px;}\n\
        .general-buttons{margin-top:150px;width:416px;position:absolute;top:528px;left:0px;}\n\
        .main{margin-left:33%;padding:0px 10px;margin-bottom:100px;margin-top:154px;}\n\
        .email-form{width: 90%; margin-left: 5%; margin-right:5%; margin-top:15px; margin-bottom: 15px;}\n\
        .sidenav{height:100%;width:33%;position:fixed;left:120px;background-color:#FFF;overflow-x:hidden;padding-top:20px;}\n\
        .header-container{white-space: nowrap;}\n\
        footer{background:#2C3E50;color:#FFF;z-index:3;position:fixed;width:-webkit-fill-available;bottom: 0;}\n\
        .dropbtn{background-color:#3498DB;color:white;padding:6px 30px;font-size:16px;border:none;cursor:pointer;font-size:30px;margin-bottom:13px;border-radius:20px;}\n\
        .dropbtn:hover, .dropbtn:focus{background-color:#2980B9;}\n\
        .dropdown{position:relative;display: inline-block;}\n\
        .dropdown-content {display: none; position: absolute;background-color: #f1f1f1; min-width: 160px;box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);z-index: 1;}\n\
        .dropdown-content a {color: black; padding: 12px 16px; text-decoration: none; display: block;}\n\
        .dropdown-content a:hover {background-color: #ddd}\n\
        .show {padding:6px 30px;}\n\
        .button-origin{background-color:#3498DB;color:white;padding: 3px 52px;font-size:16px;border:none;cursor:pointer;font-size:30px;margin-bottom:13px;border-radius:20px; width: 205.6;}\n\
        .tests {width: 466; height: 286.5; top: 528px; margin-top: 150px; position: absolute;margin-left: 520px; background: #00000009; border-radius: 16px;}\n\
        .line1{margin-left: 50px; margin-right: 50px;width: 366px;height: 7px;border-bottom: 1px solid black; position: absolute;}\n\
        .line3{width: 112px;height: 47px;border-bottom: 1px solid black; position: absolute;}\n\
        .line2{margin-left: 233px; margin-top: 18px;width: 1px;border-bottom: 118px solid black; position: absolute;}\n\
        .textWeight{display: block; text-align: center;margin-top: 28px;font-size: 18px;}\n\
        .active{}\n\
        .columnRow{}\n\
        .placeValue{width: 208px; height: 71.625px; display: flex;    margin-left: 21px;}\n\
        .textValue{font-size: 38px; font-weight: 610; margin: auto;}\n\
        .duty{}\n\
        .timeTest{}\n\
        .scrollBar{overflow: auto}\n\
        .scrollBar::-webkit-scrollbar {width: 7px; }\n\
        .scrollBar::-webkit-scrollbar-thumb {background: #ccc;border-radius: 4px;}\n\
        .scrollBar::-webkit-scrollbar-thumb:active {background-color: #999999;}\n\
        .scrollBar::-webkit-scrollbar-thumb:hover {background: #b3b3b3;box-shadow: 0 0 2px 1px rgba(0, 0, 0, 0.2);}\n\
        .scrollBar::-webkit-scrollbar-track {background: #e1e1e1; border-radius: 4px;}\n\
        .scrollBar::-webkit-scrollbar-track:hover,\n\
        .scrollBar::-webkit-scrollbar-track:active {background: #d4d4d4;}\n\
      </style>\n\
      <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js'></script>\n\
      <script type='text/javascript'>\n\
        function drawCircleFilled(x, y, radius, letra) {\n\
          var c = document.getElementById('myCanvas');\n\
          var ctx = c.getContext('2d');\n\
          ctx.beginPath();\n\
          ctx.arc(x, y, radius, 0, 2 * Math.PI);\n\
          if (letra === 'A') ctx.fillStyle = '#05A4FB';\n\
          else if (letra === 'B') ctx.fillStyle = '#FB9905';\n\
          ctx.fill();\n\
          ctx.stroke();\n\
        }\n\
        function drawRowA(fila, letra) {\n\
          drawCircleFilled(40*2 + fila*46, 106, 16, letra);\n\
          drawCircleFilled(40*2 + fila*46, 151, 16, letra);\n\
          drawCircleFilled(40*2 + fila*46, 195, 16, letra);\n\
        }\n\
        function drawRowB(fila, letra) {\n\
          drawCircleFilled(40*2 + fila*46, 106 + 45*3, 16, letra);\n\
          drawCircleFilled(40*2 + fila*46, 151 + 45*3, 16, letra);\n\
          drawCircleFilled(40*2 + fila*46, 195 + 45*3, 16, letra);\n\
        }\n\
        function myCanvas(fila, letra) {\n\
          var c = document.getElementById('myCanvas');\n\
          var ctx = c.getContext('2d');\n\
          var img = document.getElementById('scream');\n\
          ctx.drawImage(img,10,10);\n\
          if (letra === 'A') drawRowA(fila, letra);\n\
          else if (letra === 'B') drawRowB(fila, letra);\n\
          else if (fila === 0) return;\n\
        }\n\
        setInterval(function ( ) {\n\
          var xhttp = new XMLHttpRequest();\n\
          xhttp.onreadystatechange = function() {\n\
            if (this.readyState == 4 && this.status == 200) {\n\
              document.getElementById('active').innerHTML = this.responseText;\n\
            }\n\
          };\n\
          xhttp.open('GET', '/active', true);\n\
          xhttp.send();\n\
        }, 1000) ;\n\
        setInterval(function ( ) {\n\
          var xhttp = new XMLHttpRequest();\n\
          xhttp.onreadystatechange = function() {\n\
            if (this.readyState == 4 && this.status == 200) {\n\
              document.getElementById('columnRow').innerHTML = this.responseText;\n\
            }\n\
          };\n\
          xhttp.open('GET', '/columnRow', true);\n\
          xhttp.send();\n\
        }, 1000) ;\n\
        setInterval(function ( ) {\n\
          var xhttp = new XMLHttpRequest();\n\
          xhttp.onreadystatechange = function() {\n\
            if (this.readyState == 4 && this.status == 200) {\n\
              document.getElementById('power').innerHTML = this.responseText;\n\
            }\n\
          };\n\
          xhttp.open('GET', '/power', true);\n\
          xhttp.send();\n\
        }, 1000) ;\n\
        setInterval(function ( ) {\n\
          var xhttp = new XMLHttpRequest();\n\
          xhttp.onreadystatechange = function() {\n\
            if (this.readyState == 4 && this.status == 200) {\n\
              document.getElementById('power').innerHTML = this.responseText;\n\
            }\n\
          };\n\
          xhttp.open('GET', '/power', true);\n\
          xhttp.send();\n\
        }, 1000) ;\n\
        setInterval(function ( ) {\n\
          var xhttp = new XMLHttpRequest();\n\
          xhttp.onreadystatechange = function() {\n\
            if (this.readyState == 4 && this.status == 200) {\n\
              document.getElementById('frequency').innerHTML = this.responseText;\n\
            }\n\
          };\n\
          xhttp.open('GET', '/frequency', true);\n\
          xhttp.send();\n\
        }, 1000) ;\n\
        setInterval(function ( ) {\n\
          var xhttp = new XMLHttpRequest();\n\
          xhttp.onreadystatechange = function() {\n\
            if (this.readyState == 4 && this.status == 200) {\n\
              document.getElementById('duty').innerHTML = this.responseText;\n\
            }\n\
          };\n\
          xhttp.open('GET', '/duty', true);\n\
          xhttp.send();\n\
        }, 1000) ;\n\
        setInterval(function ( ) {\n\
          var xhttp = new XMLHttpRequest();\n\
          xhttp.onreadystatechange = function() {\n\
            if (this.readyState == 4 && this.status == 200) {\n\
              document.getElementById('timeTest').innerHTML = this.responseText;\n\
            }\n\
          };\n\
          xhttp.open('GET', '/timeTest', true);\n\
          xhttp.send();\n\
        }, 100) ;\n\
        $.support.cors = true;\n\
        function saveRowData(row, letter) {\n\
          const freq = $('#frequency' + row + letter).val();\n\
          const power = $('#power' + row + letter).val();\n\
          const duty = $('#duty' + row + letter).val();\n\
          const time = $('#time' + row + letter).val();\n\
          const sendInfo = {frequency: freq, power: power, duty: duty,time: time};\n\
          $.ajax({type: 'POST', contentType: 'application/json;charset=utf-8', onfocusout: false, url: 'http://192.168.1.131/row/' + row + '/' + letter, dataType: 'json', cors: true , crossDomain: true,\n\
            headers: {'Access-Control-Allow-Origin': '*',},\n\
            success: function (msg) { console.log('Data sent');},\n\
            failure: function (e) { console.log('Could not send data');},\n\
            data: JSON.stringify(sendInfo)\n\
          });\n\
        }\n\
        function startTests() {\n\
          const s = 1;\n\
          const sendInfo = {start : s};\n\
          $.ajax({type: 'POST', contentType: 'application/json;charset=utf-8', onfocusout: false, url: 'http://192.168.1.131/tests/', dataType: 'json', cors: true , crossDomain: true,\n\
            headers: {'Access-Control-Allow-Origin': '*',},\n\
            success: function (msg) { console.log('Data sent');},\n\
            failure: function (e) { console.log('Could not send data');},\n\
            data: JSON.stringify(sendInfo)\n\
          });\n\
        }\n\
        function oneStep() {\n\
          const s = 1;\n\
          const sendInfo = {start : s};\n\
          $.ajax({type: 'POST', contentType: 'application/json;charset=utf-8', onfocusout: false, url: 'http://192.168.1.131/oneStep/', dataType: 'json', cors: true , crossDomain: true,\n\
            headers: {'Access-Control-Allow-Origin': '*',},\n\
            success: function (msg) { console.log('Data sent');},\n\
            failure: function (e) { console.log('Could not send data');},\n\
            data: JSON.stringify(sendInfo)\n\
          });\n\
        }\n\
        function nextRow() {\n\
          const s = 1;\n\
          const sendInfo = {start : s};\n\
          $.ajax({type: 'POST', contentType: 'application/json;charset=utf-8', onfocusout: false, url: 'http://192.168.1.131/nextRow/', dataType: 'json', cors: true , crossDomain: true,\n\
            headers: {'Access-Control-Allow-Origin': '*',},\n\
            success: function (msg) { console.log('Data sent');},\n\
            failure: function (e) { console.log('Could not send data');},\n\
            data: JSON.stringify(sendInfo)\n\
          });\n\
        }\n\
        function stopTests() {\n\
          const s = 1;\n\
          const sendInfo = {start : s};\n\
          $.ajax({type: 'POST', contentType: 'application/json;charset=utf-8', onfocusout: false, url: 'http://192.168.1.131/stop/', dataType: 'json', cors: true , crossDomain: true,\n\
            headers: {'Access-Control-Allow-Origin': '*',},\n\
            success: function (msg) { console.log('Data sent');},\n\
            failure: function (e) { console.log('Could not send data');},\n\
            data: JSON.stringify(sendInfo)\n\
          });\n\
        }\n\
        function wavelenght(event) {\n\
          var selectElement = event.target;var value = selectElement.value;\n\
          const sendInfo = {wavelenght : value};\n\
          $.ajax({type: 'POST', contentType: 'application/json;charset=utf-8', onfocusout: false, url: 'http://192.168.1.131/wavelenght/', dataType: 'json', cors: true , crossDomain: true,\n\
            headers: {'Access-Control-Allow-Origin': '*',},\n\
            success: function (msg) { console.log('Data sent');},\n\
            failure: function (e) { console.log('Could not send data');},\n\
            data: JSON.stringify(sendInfo)\n\
          });\n\
        }\n\
        function moveToOrigin() {\n\
          const s = 1;\n\
          const sendInfo = {origin : s};\n\
          $.ajax({type: 'POST', contentType: 'application/json;charset=utf-8', onfocusout: false, url: 'http://192.168.1.131/origin/', dataType: 'json', cors: true , crossDomain: true,\n\
            headers: {'Access-Control-Allow-Origin': '*',},\n\
            success: function (msg) { console.log('Data sent');},\n\
            failure: function (e) { console.log('Could not send data');},\n\
            data: JSON.stringify(sendInfo)\n\
          });\n\
        }\n\
        function cardChecked(row, column) {\n\
          const s = row;\n\
          const  p = column;\n\
          const sendInfo = {row : s, column: p};\n\
          $.ajax({type: 'POST', contentType: 'application/json;charset=utf-8', onfocusout: false, url: 'http://192.168.1.131/show/', dataType: 'json', cors: true , crossDomain: true,\n\
            headers: {'Access-Control-Allow-Origin': '*',},\n\
            success: function (msg) { console.log('Data sent');},\n\
            failure: function (e) { console.log('Could not send data');},\n\
            data: JSON.stringify(sendInfo)\n\
          });\n\
        }\n\
      </script>\n\
    </head>\n\
    <body style='zoom: 0.5;' onload='window.scrollTo(); myCanvas(0)'>\n\
      <header>\n\
        <div class='container header-container' style='text-align: center;'>\n\
          <h1 class='title'>Photodynamic Test</h1>\n\
        </div>\n\
      </header>\n\
      <div class='sidenav'>\n\
        <div class='col-xs-12 col-sm-12 col-md-12 col-lg-12'>\n\
          <div class='disclaimer'>\n\
            <a href='https://ibb.co/Cn7DXw5'><img id='scream' src='https://i.ibb.co/FBwCfhb/ELISA1.png' border='0' width='0'></a>\n\
            <canvas id='myCanvas' width='650' height='450'\n\
              style='border:0 solid #d3d3d3;''></canvas>\n\
          </div>\n\
          <div class=''>\n\
            <div class=''>\n\
              <div class='general-buttons'>\n\
                <div class=''>\n\
                  <div class='dropdown'>\n\
                    <select  id='myDropdown' onchange='wavelenght(event)' class='dropbtn dropdown'>\n\
                      <option value='1' href='#wl1'>660 nm</option>\n\
                      <option value='2' href='#wl2'>810 nm</option>\n\
                      <option value='3' href='#wl3'>1300nm</option>\n\
                    </select >\n\
                    <button class='button-origin addMore' title='Origin' \n\
                    onclick='moveToOrigin();'>Origin</button>\n\
                  </div>\n\
                </div>\n\
                <div class=''>\n\
                  <button class='button-start-rows addMore' title='Start test' \n\
                    onclick='startTests();'>Start Tests</button>\n\
                </div>\n\
                <div class=''>\n\
                  <button class='addMore' style='font-size: 30px; margin: 0px; color: white; margin-top: 13px; border-radius: 20px; border: #F94C4C; width: 100%; margin-bottom: 13px; background: #F94C4C' title='Stop Tests' \n\
                    onclick='stopTests();'>Stop Tests</button>\n\
                </div>\n\
                <div class=''>\n\
                  <div class='dropdown'style='margin-top: 11px;'>\n\
                    <button class='button-origin addMore' title='Move to next Row' \n\
                    onclick='nextRow();'>N.Row</button>\n\
                    <button class='button-origin addMore' title='One step' \n\
                    onclick='oneStep();'>O.Step</button>\n\
                  </div>\n\
                </div>\n\
              </div>\n\
              <div class='tests cardBox'>\n\
                <div class='active'>\n\
                  <p class='' style = 'margin-top: 7px; font-weight: 700; margin-bottom: 0;display: block; font-size: 38px;\n\
                  text-align: center; margin-left: auto;'id='active'> %active%</p>\n\
                </div>\n\
                <div class='line1'>\n\
                </div>\n\
                <div class='columnRow'>\n\
                  <p class='' style = 'margin-top: 7px; font-weight: 700;margin-bottom: 0; display: block; font-size: 38px;\n\
                  text-align: center; margin-left: auto;'id='columnRow'> %columnRow%</p>\n\
                </div>\n\
                <div class='line1'>\n\
                </div>\n\
                <div style='display: flex; flex-wrap: wrap;margin-top: 9px;'>\n\
                  <div class='placeValue'>\n\
                    <p class='textValue' id='power'> %power%</p>\n\
                    <p class='textValue' style='margin-left: 0px;' id = 'W'>W</p>\n\
                  </div>\n\
                  <div class='placeValue'>\n\
                    <p class='textValue' id='frequency'> %frequency%</p>\n\
                    <p class='textValue' style='margin-left: 0px;' id = 'Hz'>Hz</p>\n\
                  </div>\n\
                  <div class='line2'>\n\
                  </div>\n\
                  <div class='placeValue'>\n\
                    <p class='textValue' id='duty'> %duty%</p>\n\
                    <p class='textValue'style='margin-left: 0px;' id = '%'>%</p>\n\
                  </div>\n\
                  <div class='placeValue'>\n\
                    <p class='textValue' id='timeTest'> %timeTest%</p>\n\
                    <p class='textValue' style='margin-left: 0px;'id = 's'>s</p>\n\
                  </div>\n\
                </div>\n\
              </div>\n\
            </div>\n\
          </div>\n\
        </div>\n\
      </div>\n\
      <div class='main'>\n\
        <div class = 'scrollBar' style = 'margin-left: 230px;'>\n\
        <div onmouseover='myCanvas(1,\"A\" )' class='cardBox col-6 card card-header-style card-style'>\n\
          <p class='card-text'>\n\
            Column 1A</p>\n\
          <div class='custom-control custom-checkbox checkbox-class'>\n\
            <input onclick='cardChecked(1, 0)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection1A'>\n\
            <label class='custom-control-label' for='selection1A'></label>\n\
          </div>\n\
          <form onsubmit='return false'class='form-container'>\n\
            <div class='form-variable-control'>\n\
              <input class='form-variable-control' value='' title='' id='frequency1A' name='frequency1A' type='text' placeholder='Frequency (Hz)'\n\
                onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
                onblur='if(this.value==\"\") {this.value=this.title;}'\n\
                oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
                if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
            </div>\n\
            <div class='form-variable-control'>\n\
              <input class='form-variable-control' value='' title='' id='time1A' name='time1A' type='text' placeholder='Time (min)'\n\
                onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
                onblur='if(this.value==\"\") {this.value=this.title;}'\n\
                oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
                if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
            </div>\n\
            <div class='form-variable-control'>\n\
              <input class='form-variable-control' value='' title='' id='power1A' name='power1A' type='text' placeholder='Power (W)'\n\
                onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
                onblur='if(this.value==\"\") {this.value=this.title;}'\n\
                oninput='if (this.value<0 || this.value>300) {this.value=this.title;}\n\
                if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
            </div>\n\
            <div class='form-variable-control'>\n\
              <input class='form-variable-control' value='' title='' id='duty1A' name='duty1A' type='text' placeholder='Duty (%)'\n\
                onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
                onblur='if(this.value==\"\") {this.value=this.title;}'\n\
                oninput='if (this.value<0 || this.value>300) {this.value=this.title;}\n\
                if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
            </div>\n\
            <div class='form-variable-control'>\n\
              <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
                onclick='saveRowData(1, \"A\");'>Save</button>\n\
            </div>\n\
          </form>\n\
        </div>\n\
        <div onmouseover='myCanvas(1, \"B\")' class=' cardBox col-6 card card-header-style card-style'>\n\
          <p class='card-text'>\n\
            Column 1B</p>\n\
          <div class='custom-control custom-checkbox  checkbox-class'>\n\
            <input onclick='cardChecked(1, 1)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection1B'>\n\
            <label class='custom-control-label' for='selection1B'></label>\n\
          </div>\n\
          <form onsubmit='return false'class='form-container'>\n\
            <div class='form-variable-control'>\n\
              <input class='form-variable-control' value='' title='' id='frequency1B' name='frequency1B' type='text' placeholder='Frequency (Hz)'\n\
                onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
                onblur='if(this.value==\"\") {this.value=this.title;}'\n\
                oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
                if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
            </div>\n\
            <div class='form-variable-control'>\n\
              <input class='form-variable-control' value='' title='' id='time1B' name='time1B' type='text' placeholder='Time (min)'\n\
                onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
                onblur='if(this.value==\"\") {this.value=this.title;}'\n\
                oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
                if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
            </div>\n\
            <div class='form-variable-control'>\n\
              <input class='form-variable-control' value='' title='' id='power1B' name='power1B' type='text' placeholder='Power (W)'\n\
                onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
                onblur='if(this.value==\"\") {this.value=this.title;}'\n\
                oninput='if (this.value<0 || this.value>0.8) {this.value=this.title;}\n\
                if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
            </div>\n\
            <div class='form-variable-control'>\n\
              <input class='form-variable-control' value='' title='' id='duty1B' name='duty1B' type='text' placeholder='Duty (%)'\n\
                onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
                onblur='if(this.value==\"\") {this.value=this.title;}'\n\
                oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
                if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
            </div>\n\
            <div class='form-variable-control'>\n\
              <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
                onclick='saveRowData(1, \"B\");'>Save</button>\n\
            </div>\n\
          </form>\n\
        </div>\n\
      <div onmouseover='myCanvas(2, \"A\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 2A</p>\n\
        <div class='custom-control custom-checkbox checkbox-class'>\n\
          <input onclick='cardChecked(2, 0)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection2A'>\n\
          <label class='custom-control-label' for='selection2A'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency2A' name='frequency2A' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time2A' name='time2A' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power2A' name='power2A' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>10.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty2A' name='duty2A' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(2, \"A\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(2, \"B\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 2B</p>\n\
        <div class='custom-control custom-checkbox  checkbox-class'>\n\
          <input onclick='cardChecked(2, 1)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection2B'>\n\
          <label class='custom-control-label' for='selection2B'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency2B' name='frequency2B' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time2B' name='time2B' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power2B' name='power2B' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>10.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty2B' name='duty2B' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(2, \"B\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(3, \"A\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 3A</p>\n\
        <div class='custom-control custom-checkbox checkbox-class'>\n\
          <input onclick='cardChecked(3, 0)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection3A'>\n\
          <label class='custom-control-label' for='selection3A'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency3A' name='frequency3A' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time3A' name='time3A' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power3A' name='power3A' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty3A' name='duty3A' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(3, \"A\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(3, \"B\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 3B</p>\n\
        <div class='custom-control custom-checkbox  checkbox-class'>\n\
          <input onclick='cardChecked(3, 1)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection3B'>\n\
          <label class='custom-control-label' for='selection3B'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency3B' name='frequency3B' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time3B' name='time3B' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power3B' name='power3B' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty3B' name='duty3B' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(3, \"B\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(4, \"A\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 4A</p>\n\
        <div class='custom-control custom-checkbox checkbox-class'>\n\
          <input onclick='cardChecked(4, 0)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection4A'>\n\
          <label class='custom-control-label' for='selection4A'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency4A' name='frequency4A' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time4A' name='time4A' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power4A' name='power4A' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty4A' name='duty4A' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(4, \"A\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(4, \"B\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 4B</p>\n\
        <div class='custom-control custom-checkbox  checkbox-class'>\n\
          <input onclick='cardChecked(4, 1)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection4B'>\n\
          <label class='custom-control-label' for='selection4B'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency4B' name='frequency4B' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time4B' name='time4B' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power4B' name='power4B' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty4B' name='duty4B' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(4, \"B\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(5, \"A\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 5A</p>\n\
        <div class='custom-control custom-checkbox checkbox-class'>\n\
          <input onclick='cardChecked(5, 0)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection5A'>\n\
          <label class='custom-control-label' for='selection5A'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency5A' name='frequency5A' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time5A' name='time5A' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power5A' name='power5A' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty5A' name='duty5A' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(5, \"A\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(5, \"B\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 5B</p>\n\
        <div class='custom-control custom-checkbox  checkbox-class'>\n\
          <input onclick='cardChecked(5, 1)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection5B'>\n\
          <label class='custom-control-label' for='selection5B'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency5B' name='frequency5B' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time5B' name='time5B' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power5B' name='power5B' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty5B' name='duty5B' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(5, \"B\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(6, \"A\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 6A</p>\n\
        <div class='custom-control custom-checkbox checkbox-class'>\n\
          <input onclick='cardChecked(6, 0)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection6A'>\n\
          <label class='custom-control-label' for='selection6A'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency6A' name='frequency6A' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time6A' name='time6A' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power6A' name='power6A' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty6A' name='duty6A' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(6, \"A\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(6, \"B\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 6B</p>\n\
        <div class='custom-control custom-checkbox  checkbox-class'>\n\
          <input onclick='cardChecked(6, 1)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection6B'>\n\
          <label class='custom-control-label' for='selection6B'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency6B' name='frequency6B' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time6B' name='time6B' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power6B' name='power6B' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty6B' name='duty6B' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(6, \"B\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(7, \"A\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 7A</p>\n\
        <div class='custom-control custom-checkbox checkbox-class'>\n\
          <input onclick='cardChecked(7, 0)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection7A'>\n\
          <label class='custom-control-label' for='selection7A'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency7A' name='frequency7A' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time7A' name='time7A' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power7A' name='power7A' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty7A' name='duty7A' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(7, \"A\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(7, \"B\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 7B</p>\n\
        <div class='custom-control custom-checkbox  checkbox-class'>\n\
          <input onclick='cardChecked(7, 1)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection7B'>\n\
          <label class='custom-control-label' for='selection7B'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency7B' name='frequency7B' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time7B' name='time7B' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power7B' name='power7B' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty7B' name='duty7B' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;'class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(7, \"B\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(8, \"A\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 8A</p>\n\
        <div class='custom-control custom-checkbox checkbox-class'>\n\
          <input onclick='cardChecked(8, 0)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection8A'>\n\
          <label class='custom-control-label' for='selection8A'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency8A' name='frequency8A' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time8A' name='time8A' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power8A' name='power8A' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty8A' name='duty8A' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(8, \"A\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(8, \"B\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 8B</p>\n\
        <div class='custom-control custom-checkbox  checkbox-class'>\n\
          <input onclick='cardChecked(8, 1)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection8B'>\n\
          <label class='custom-control-label' for='selection8B'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency8B' name='frequency8B' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time8B' name='time8B' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power8B' name='power8B' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty8B' name='duty8B' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(8, \"B\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(9, \"A\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 9A</p>\n\
        <div class='custom-control custom-checkbox checkbox-class'>\n\
          <input onclick='cardChecked(9, 0)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection9A'>\n\
          <label class='custom-control-label' for='selection9A'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency9A' name='frequency9A' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time9A' name='time9A' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power9A' name='power9A' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty9A' name='duty9A' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(9, \"A\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(9, \"B\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 9B</p>\n\
        <div class='custom-control custom-checkbox  checkbox-class'>\n\
          <input onclick='cardChecked(9, 1)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection9B'>\n\
          <label class='custom-control-label' for='selection9B'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency9B' name='frequency9B' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time9B' name='time9B' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power9B' name='power9B' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty8B' name='duty9B' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(9, \"B\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(10, \"A\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 10A</p>\n\
        <div class='custom-control custom-checkbox checkbox-class'>\n\
          <input onclick='cardChecked(10, 0)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection10A'>\n\
          <label class='custom-control-label' for='selection10A'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency10A' name='frequency10A' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time10A' name='time10A' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power10A' name='power10A' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty10A' name='duty10A' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(10, \"A\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
      <div onmouseover='myCanvas(10, \"B\")' class='cardBox col-6 card card-header-style card-style'>\n\
        <p class='card-text'>\n\
          Column 10B</p>\n\
        <div class='custom-control custom-checkbox  checkbox-class'>\n\
          <input onclick='cardChecked(10, 1)' type='checkbox' class='custom-control-input enabled-checkbox' id='selection10B'>\n\
          <label class='custom-control-label' for='selection10B'></label>\n\
        </div>\n\
        <form onsubmit='return false'class='form-container'>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='frequency10B' name='frequency10B' type='text' placeholder='Frequency (Hz)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='time10B' name='time10B' type='text' placeholder='Time (min)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100000) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='power10B' name='power10B' type='text' placeholder='Power (W)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>1.0) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <input class='form-variable-control' value='' title='' id='duty10B' name='duty10B' type='text' placeholder='Duty (%)'\n\
              onfocus='if(this.value==this.title) {this.value=\"\";}'\n\
              onblur='if(this.value==\"\") {this.value=this.title;}'\n\
              oninput='if (this.value<0 || this.value>100) {this.value=this.title;}\n\
              if (isNaN(this.value) == 1) {this.value=this.title}'>\n\
          </div>\n\
          <div class='form-variable-control'>\n\
            <button style = 'margin-top: 24px;' class='button-start-rows addMore' title='Save Test Parameters' \n\
              onclick='saveRowData(10, \"B\");'>Save</button>\n\
          </div>\n\
        </form>\n\
      </div>\n\
    </div>\n\
  </div>\n\
  </div>\n\
  <footer>\n\
    <div class='container'>\n\
      <h1 style='text-align: center;'>Universidad de Oviedo</h1>\n\
    <div>\n\
  </footer>\n\
</body>\n\
</html>";