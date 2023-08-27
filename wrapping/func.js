const add = Module.cwrap(
    "addNum",
    "number",
    ["number", "number"]
)
const sub = Module.cwrap(
    "subNum",
    "number",
    ["number", "number"]
)
const mul = Module.cwrap(
    "mulNum",
    "number",
    ["number", "number"]
)
const div = Module.cwrap(
    "divNum",
    "number",
    ["number", "number"]
)

function addNum(){
    const a = document.querySelector("#a").value;
    const b = document.querySelector("#b").value;
    document.querySelector("#c").innerHTML = add(a, b);
}
function subNum(){
    const a = document.querySelector("#a").value;
    const b = document.querySelector("#b").value;
    document.querySelector("#c").innerHTML = sub(a, b);

}
function mulNum(){
    const a = document.querySelector("#a").value;
    const b = document.querySelector("#b").value;
    document.querySelector("#c").innerHTML = mul(a, b);
}
function divNum(){
    const a = document.querySelector("#a").value;
    const b = document.querySelector("#b").value;
    document.querySelector("#c").innerHTML = div(a, b);
}