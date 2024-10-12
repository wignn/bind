const addon = require('./build/Release/addon');

function jsSum() {
    let a = 5.4563, b = 9.5879;
    for (let i = 0; i < 1000000; i++) {
        a += b;
    }

    function isPrismNumber(n) {
        let sum = 0;
        for (let i = 1; i <= n; i++) {
            sum += i;
            if (sum === n) return true;
        }
        return false;
    }

    let prismNumbers = [];
    for (let i = 1; i <= 1000; i++) {
        if (isPrismNumber(i)) {
            prismNumbers.push(i);
        }
    }
    console.log('Bilangan Prisma:', prismNumbers);
    let total = a;
    return total;
}

console.log("JS");
console.time('JS Time');
console.log(jsSum());
console.timeEnd('JS Time');

console.log("\n");

console.log("C++");
console.time('C++ Time');
console.log(addon.sum());
console.timeEnd('C++ Time');

function printMatrixStyle(numbers) {
    const matrixChar = '🔹'; 
    const rows = process.stdout.columns; 

    let output = '';
    for (let number of numbers) {
        output += `${matrixChar}${number.toString().padStart(3, ' ')} `;
        if (output.length >= rows) {
            console.log(output);
            output = ''; 
        }
    }
    if (output) {
        console.log(output); 
    }
}

console.log("C++ - Bilangan prima:");
let cppPrismNumbers = [];
for (let i = 1; i <= 1000; i++) {
    if (addon.isPrismNumber(i)) {
        cppPrismNumbers.push(i);
    }
}

printMatrixStyle(cppPrismNumbers);
