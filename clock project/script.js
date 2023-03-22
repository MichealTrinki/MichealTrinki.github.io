var nameNode = document.getElementById("name");
nameNode.addEventListener("click", function () {
    alert("Welcome to My Site!")
}) 
let display = document.getElementById("display");
let button = document.getElementsByTagName("button");

Array.from(button).forEach((elem) => {
    elem.addEventListener("click", calculate)
});

function calculate() {
    let digit = this.id;
    if (display.innerText.length < 13) {
     if (digit = 'C')  {
     display.innerText = "";
    }  else if (digit = 'AC') {
     let array = Array.from(display.innerText);
      array.pop();
      display.innerText = array.join('')
    } else if (digit = "=") {
     display.innerText = eval(display.innerText);
    } else {
     display.innerText +=digit;
    }
} else {
    alert("out of range");
    let array = Array.from(display.innerText);
    array = array.splice(0,13);
    display.innerText = array.join('');
}
}