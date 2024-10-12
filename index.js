const addon = require('./build/Release/addon');n

function jsSum(){
    let a = 5.4563, b = 9.5879;
    for(let i = 0; i < 1000000; i++){
        a += b;
    }

    let total = a;
    return total;
}

console.log("hello")
console.log(addon.hello());
console.time('JS Time');
console.log(jsSum());
console.log("c++")
console.log(addon.sum());