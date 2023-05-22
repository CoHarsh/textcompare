const { exec } = require('child_process');
const path = require('path');


const cppFilePath = path.join(__dirname, 'LogicFile', 'percentage.cpp');
const compiledFilePath = path.join(__dirname, 'compiled');
const compileCommand = `g++ -o ${compiledFilePath} ${cppFilePath}`;
const executeCommand = `${compiledFilePath}`;

const createchildprocess = () => {
  const childprocess = exec(executeCommand, (executeError, stdout, stderr) => {
    if (executeError) {
      console.error(`Error executing the C++ program: ${executeError}`);
      return;
    }

    console.log('C++ program executed successfully!');
    console.log('Output:');
    console.log(stdout);

    if (stderr) {
      console.error('Error:');
      console.error(stderr);
    }
  });
  return childprocess;
}


function compareideal(s1,s2,start){
    const childprocessptr = createchildprocess();
    const command = 'compareideal';
    childprocessptr.stdin.write(`${command}\n`);
    childprocessptr.stdin.write(`${s1}\n`);
    childprocessptr.stdin.write(`${s2}\n`);
    childprocessptr.stdin.write(`${start}\n`);
    childprocessptr.stdin.end();
    return childprocessptr;
}

function removespace(str){
    const childprocessptr = createchildprocess();
    const command = 'removespace';
    childprocessptr.stdin.write(`${command}\n`);
    childprocessptr.stdin.write(`${str}\n`);
    childprocessptr.stdin.end();
    return childprocessptr;
}

function topkfreq(str,k){
    const childprocessptr = createchildprocess();
    const command = 'topkfreq';
    childprocessptr.stdin.write(`${command}\n`);
    childprocessptr.stdin.write(`${str}\n`);
    childprocessptr.stdin.write(`${k}\n`);
    childprocessptr.stdin.end();
    return childprocessptr;
}

function similarity(inputString1,inputString2){
    const childprocessptr = createchildprocess();
    const command = 'similarity';
    childprocessptr.stdin.write(`${command}\n`);
    childprocessptr.stdin.write(`${inputString1}\n`);
    childprocessptr.stdin.write(`${inputString2}\n`);
    childprocessptr.stdin.end();
    return childprocessptr;
}

function uppercase(str){
    const childprocessptr = createchildprocess();
    const command = 'uppercase';
    childprocessptr.stdin.write(`${command}\n`);
    childprocessptr.stdin.write(`${str}\n`);
    childprocessptr.stdin.end();
    return childprocessptr;
}

function lowercase(str){
    const childprocessptr = createchildprocess();
    const command = 'lowercase';
    childprocessptr.stdin.write(`${command}\n`);
    childprocessptr.stdin.write(`${str}\n`);
    childprocessptr.stdin.end();
    return childprocessptr;
}

exec(compileCommand, (compileError) => {
  if (compileError) {
    console.error(`Error compiling the C++ file: ${compileError}`);
    return;
  }
});



// const command = 'compareideal';
// if(command === 'similarity'){
//     const inputString1 = 'Input String 1';
//     const inputString2 = 'Input String 2';
//     similarity(childProcess,command,inputString1,inputString2);
// }
// else if(command === 'topkfreq'){
//     const inputString1 = 'Input String String 1';
//     const k = 6;
//     topkfreq(childProcess,command,inputString1,k);
// }
// else if(command === 'uppercase'){
//     const str = 'Input String String 1';
//     uppercase(childProcess,command,str);
// }
// else if(command === 'lowercase'){
//     const str = 'INPUT STRING STRING 1';
//     lowercase(childProcess,command,str);
// }
// else if(command === "removespace"){
//     const str = '   Input      String String 1';
//     removespace(childProcess,command,str);
// }
// else if(command === "compareideal"){
//     const s1 = "harsh@gmail.com";
//     const s2 = "@gmail.com";
//     const start = "first";
//     compareideal(childProcess,command,s1,s2,start);
// }
//   childprocessptr.stdin.end();



module.exports = {
    compareideal,
    removespace,
    topkfreq,
    similarity,
    uppercase,
    lowercase
}