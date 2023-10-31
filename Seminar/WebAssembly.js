let exports;
let memory = new WebAssembly.Memory({
    initial: 256,
    maximum: 512
});
WebAssembly.instantiateStreaming(
    fetch("streaming.wasm"), {
        js:{
            mem: memory
        },
        env:{
            emscripten_resize_heap: function (delta) {memory.grow(delta);}
        }
    }
).then(result => {
    exports = result.instance.exports
    memory = result.instance.exports.memory;
});

function add(){
    const a = document.querySelector("#a").value;
    const b = document.querySelector("#b").value;
    let result = exports.add(a,b);
    result = result.toFixed(2);

    document.querySelector("#ret")
        .innerHTML = `${a} + ${b} => ${result}<br/>`
}

function sub(){
    const a = document.querySelector("#a").value;
    const b = document.querySelector("#b").value;
    let result = exports.sub(a,b);
    result = result.toFixed(2);

    document.querySelector("#ret")
        .innerHTML = `${a} - ${b} => ${result}<br/>`
}

function mul(){
    const a = document.querySelector("#a").value;
    const b = document.querySelector("#b").value;
    let result = exports.mul(a,b);
    result = result.toFixed(2);

    document.querySelector("#ret")
        .innerHTML = `${a} * ${b} => ${result}<br/>`
}

function div(){
    const a = document.querySelector("#a").value;
    const b = document.querySelector("#b").value;
    let result = exports.div_l(a,b);
    result = result.toFixed(2);

    document.querySelector("#ret")
        .innerHTML = `${a} / ${b} => ${result}<br/>`
}

function collataz(){
    let num = document.querySelector("#c_num").value;
    document.querySelector("#sub")
        .innerHTML = ` `;

    while (true) {
        document.querySelector("#sub")
            .innerHTML += `=>${num} `
        if (num === 1) {
            break;
        }
        num = exports.collatz(num);
    }
}

function run_eval(){
    function evaluateExpression(expression) {
        try {
            return eval(expression);
        } catch (error) {
            return "Error: " + error.message;
        }
    }

    const inputExpression = document.querySelector("#eval_num").value;
    const result = evaluateExpression(inputExpression);
    document.querySelector("#eval_out")
        .innerHTML = `Evaluation: ${result}`
}