// const p = [
//   { id: 1, name: "abc", price: 1200, instock: true },
//   { id: 2, name: "def", price: 900, instock: false },
//   { id: 3, name: "ask", price: 2000, instock: true },
//   { id: 4, name: "oks", price: 1000, instock: true },
// ];

// const result = p
//   .filter(function (product) {
//     return product.instock == true;
//   })
//   .sort(function (a, b) {
//     if (a.price > b.price) {
//       return 1;
//     } else if (a.price < b.price) {
//       return -1;
//     } else {
//       return 0;
//     }
//   })
//   .map(function (product) {
//     let discount = (product.price * 10) / 100;
//     product.price = product.price - discount;
//     return product;
//   });

// console.log(result);
let box = document.getElementById("textBox");

box.addEventListener("input", function () {
  let text = box.value;
  let lastChar = text[text.length - 1];

  if (lastChar === lastChar.toUpperCase()) {
    lastChar = lastChar.toLowerCase();
  } else {
    lastChar = lastChar.toUpperCase();
  }

  box.value = text.slice(0, text.length - 1) + lastChar;
});
