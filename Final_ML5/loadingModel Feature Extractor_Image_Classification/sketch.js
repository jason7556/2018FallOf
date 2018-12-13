// Daniel Shiffman
// http://youtube.com/thecodingtrain
// http://codingtra.in

// Transfer Learning Feature Extractor Classification with ml5
// https://youtu.be/eeO-rWYFuG0

let mobilenet;
let classifier;
let video;
let label = 'loading model';

var serial;
var portName = '/dev/cu.usbmodem146201';
var outMessage = 's';
var outMessageC = 'c';
var outMessageS = 's';
var outMessageE = 'e';

var screenImages;
var classroomImages;
var ericImages;
var pplImages;

let eircButton;
let classroomButton;
let pplButton;
let trainButton;

var n;

function modelReady() {
  console.log('Model is ready!!!');
  classifier.load('model.json', customModelReady);
}

function videoReady() {
  console.log('Video is ready!!!');
}

function customModelReady(){
  console.log('Custom Model is ready!!!');
  label = 'model ready';
  classifier.classify(gotResults);
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
  createCanvas(640, 600);

  serial = new p5.SerialPort();
  serial.open(portName,9600);

  video = createCapture(VIDEO);
  video.hide();
  background(0);
  mobilenet = ml5.featureExtractor('MobileNet', modelReady);
  mobilenet.numClasses=4;
  classifier = mobilenet.classification(video, videoReady);

  screenImages = 562;
  classroomImages = 93;
  ericImages = 76;
  pplImages = 81;

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

  n = 0;

}

function draw() {


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

  text('Screen Images: ' + screenImages, 10, height - 70 );
  text('People Images: ' + pplImages,10, height - 50);
  text('Eric Images: ' + ericImages,10, height - 30);
  text('Classroom Images: ' + classroomImages,10, height - 10);

}

// function mouseReleased() {
//   serial.write(outMessage);
//   if (outMessage === 's') {
//     outMessage = 'c';
//   } else {
//     outMessage = 's';
//   }
// }
