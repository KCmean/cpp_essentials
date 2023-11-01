function getIndicesWithSum(arr, n, sum) {
    let indices = []; 

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] === sum) {
                indices.push([i, j]);
            }
        }
    }

    return indices;
}



let arr = [1, 5, 7, -1, 5];
let n = arr.length;
let sum = 6;

let indices = getIndicesWithSum(arr, n, sum);

// for (let indexPair of indices) {
//      document.write("Indices with sum " + sum + ": " + indexPair + "<br>");
// }

console.log(indices);
