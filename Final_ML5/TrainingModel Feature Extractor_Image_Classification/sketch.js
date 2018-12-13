// Daniel Shiffman
// http://youtube.com/thecodingtrain
// http://codingtra.in

// Transfer Learning Feature Extractor Classification with ml5
// https://youtu.be/eeO-rWYFuG0

let mobilenet;
let classifier;
let video;
let label = 'Loading Model..';

var serial;
var portName = '/dev/cu.usbmodem146201';
var outMessage = 's';
var outMessageC = 'c';
var outMessageS = 's';
var outMessageE = 'e';

// let screenImages = 562;
// let classroomImages = 93;
// let ericImages = 76;
// let pplImages = 81;

let screenImages = 50;
let classroomImages = 30;
let ericImages = 20;
let pplImages = 40;

var screenImg =[];
var classroomImg = [];
var ericImg = [];
var pplImg = [];

let eircButton;
let classroomButton;
let pplButton;
let trainButton;

var inData;


function modelReady() {
  console.log('Model is ready!!!');
  label = 'Start!';
}

function videoReady() {
  console.log('Video is ready!!!');
}

function whileTraining(loss) {
  if (loss == null) {
    console.log('Training Complete');
    classifier.classify(gotResults);
  } else {
    console.log(loss);
  }
}

function gotResults(error, result) {
  if (error) {
    console.error(error);
  } else {
    label = result;
    classifier.classify(gotResults);
  }
}

function setup() {
  createCanvas(640, 550);

  serial = new p5.SerialPort();
  serial.open(portName,9600);

  video = createCapture(VIDEO);
  video.hide();
  background(0);
  mobilenet = ml5.featureExtractor('MobileNet', modelReady);
  mobilenet.numClasses = 4;
  classifier = mobilenet.classification(video, videoReady);

  ericButton = createButton('Eric');
  ericButton.mousePressed(function() {
  classifier.addImage('Eric');
  ericImages++;
  });

  classroomButton = createButton('Classroom');
  classroomButton.mousePressed(function() {
  classifier.addImage('classroom');
  classroomImages++;
  });

  pplButton = createButton('People');
  pplButton.mousePressed(function() {
  classifier.addImage('people');
  classroomImages++;
  });

  trainButton = createButton('train');
  trainButton.mousePressed(function() {
  classifier.train(whileTraining);
  });

  saveButton = createButton('save');
  saveButton.mousePressed(function() {
  classifier.save();
  });

  // Eric Images

  for(var i=0 ; i< ericImages ; i++){
    var images = createImg('ericImages/' + i + '.jpg');
    ericImg[i]= images;
    ericImg[i].hide();
  }

  for (var i=0 ; i<ericImages ; i++){
    classifier.addImage(ericImg[i] , 'eric');
  }


  // Screen Images

  for(var i=0 ; i< screenImages ; i++){
    var images = createImg('images/' + i + '.jpg');
    screenImg[i]= images;
    screenImg[i].hide();
  }

  for (var i=0 ; i<screenImages ; i++){
    classifier.addImage(screenImg[i] , 'screen');
  }


  // Classroom Images

  for(var i=0 ; i< classroomImages ; i++){
    var images = createImg('classroomImages/' + i + '.jpg');
    classroomImg[i]= images;
    classroomImg[i].hide();
  }

  for (var i=0 ; i<classroomImages ; i++){
    classifier.addImage(classroomImg[i] , 'classroom');
  }

  // People Images

  for(var i=0 ; i< pplImages ; i++){
    var images = createImg('pplImages/' + i + '.jpg');
    pplImg[i]= images;
    pplImg[i].hide();
  }

  for (var i=0 ; i<pplImages ; i++){
    classifier.addImage(pplImg[i] , 'people');
  }
}

function draw() {

  inData = serial.read();


  if (inData == 2){
  console.log('EricImage+1');
  classifier.addImage('Eric');
  ericImages++;
  }

  if (inData == 3){
  console.log('trainModel');
  classifier.train(whileTraining);
  }

	if ( random(1) < 0.1 ){
    if (label === 'classroom' || label ==='people'){
    serial.write(outMessageC);
    }
    else if (label === 'screen'){
    serial.write(outMessageS);
    }
    else if (label === 'eric'){
    serial.write(outMessageE);
    }
  }


  background(0);
  image(video, 0, 0, 640, 480);
  fill(255);
  textSize(16);
  text(label, 10, height - 90);

  text('inData: ' + inData,10, height - 110);
  text('People Images: ' + pplImages,10, height - 70);
  text('Classroom Images: ' + classroomImages,10, height - 50);
  text('Eric Images: ' + ericImages,10, height - 30);
  text('Screen Images: ' + screenImages, 10, height - 10 );
}

function mouseReleased() {
  serial.write(outMessage);
  if (outMessage === 's') {
    outMessage = 'c';
  } else {
    outMessage = 's';
  }
}

// function serialEvent() {
//   // read a string from the serial port:
//   var inString = serial.read();
//   // check to see that there's actually a string there:
//   if (inString.length > 0 ) {
//   // convert it to a number:
//   inData = Number(inString);
//   }
//
// }
