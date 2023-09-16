const addNum = Module.cwrap(
    "numAdd",
    "number",
    ["number", "number"]
);

const subNum = Module.cwrap(
    "numSub",
    "number",
    ["number","number"]
)

function run_wasm(){
    const result = Module.ccall(
        "main",
        "number",
        null,
        null
    );
    console.log(result);
}
function add() {
    let a = document.querySelector("#a").value;
    let b = document.querySelector("#b").value;

    const result = Module.ccall(
        "numAdd",
        "number",
        ["number","number"],
        [a,b]
    )
    console.log(result)
}

function d_add(){
    let a = document.querySelector("#a").value;
    let b = document.querySelector("#b").value;

    console.log(addNum(a,b));
}