const algorithm = require('./lib/main.node')

module.exports = function floatToFraction(floatInput) {
  floatInput = Math.round(floatInput * 100000) / 100000;
  const returnString = algorithm.start_algo(floatInput);
  const arrRes = returnString.split("/");
  arrRes.map((val, i, arr) => {
    arr[i] = Number(val);
  })
  
  console.log(returnString);
  return arrRes
};




