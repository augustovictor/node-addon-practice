// 1. Build binary. This needs to bem ran every time the c++ file changes.
// node-gyp configure build

// Require addon
// const addon = require('./build/Release/addon');
const Benchmark = require('benchmark');
const suite = new Benchmark.Suite;

const addon = require('./build/Release/addon-sum.node');

function jsSum() {
    let a = 3.1415926;
    let b = 2.718;

    for(let i = 0; i < 10000000; i++) {
        a += b;
    }
    let total = a;
    return total;
}

suite
.add('JS - SUM', () => {
    jsSum();
})
.add('C++ - SUM', () => {
    addon.sum();
})
.on('cycle', function(event) {
    console.log(String(event.target));
})
.on('complete', function(a, b) {
    console.log(`Fastest: ${this.filter('fastest').map('name')}`);
    console.log(`Slowest: ${this.filter('slowest').map('name')}`);
})
.run({'async': true});



// console.time('c++');
// addon.sum();
// console.timeEnd('c++');

// console.time('js');
// jsSum();
// console.timeEnd('js');