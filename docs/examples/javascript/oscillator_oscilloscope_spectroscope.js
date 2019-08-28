const audioCtx = new AudioContext();
var freq = 172;

//Oscillator
const oscillator = audioCtx.createOscillator();
oscillator.frequency.value = freq;
oscillator.type = "sawtooth";
//const oscillator2 = audioCtx.createOscillator();
//oscillator2.frequency.value = freq *2;
//oscillator2.type = "sine";
//const oscillator3 = audioCtx.createOscillator();
//oscillator3.frequency.value = freq *3;
//oscillator3.type = "sine";

const oscillatorGain = audioCtx.createGain();
oscillatorGain.gain.value = 0.1;

oscillator.connect(oscillatorGain);
//oscillator2.connect(oscillatorGain);
//oscillator3.connect(oscillatorGain);

oscillatorGain.connect(audioCtx.destination);

oscillator.start();
//oscillator2.start();
//oscillator3.start();

function frequencychange() {
	oscillator.frequency.value = document.getElementById('frequency').value;
	oscillator2.frequency.value = document.getElementById('frequency').value *2;
	oscillator3.frequency.value = document.getElementById('frequency').value *3;
	document.getElementById('freq-display').innerHTML = oscillator.frequency.value;
}

// Oscilloscope
var analyser = audioCtx.createAnalyser();

oscillator.connect(analyser);

analyser.fftSize = 2048;
var bufferLength = analyser.frequencyBinCount;
var dataArray = new Uint8Array(bufferLength);

var osc = document.getElementById('oscilloscope');
var oscCtx = osc.getContext('2d');
oscCtx.clearRect(0,0,osc.width,osc.height);

function drawosc(){
	var drawVisual = requestAnimationFrame(drawosc);

	analyser.getByteTimeDomainData(dataArray);
	oscCtx.fillStyle = 'rgb(200,200,200)';
	oscCtx.fillRect(0,0,osc.width,osc.height);
	oscCtx.lineWidth = 2;
	oscCtx.strokeStyle = 'rgb(0,0,0)';
	oscCtx.beginPath();
	var sliceWidth = osc.width * 1.0 /bufferLength;
	var x = 0;
	for(var i =0; i < bufferLength; i++){
		var v = dataArray[i]/128.0;
		var y = v * osc.height/2;

		if(i ===0){
			oscCtx.moveTo(x,y);
		}else{
			oscCtx.lineTo(x,y);
		}
		x += sliceWidth;
	}
	oscCtx.lineTo(osc.width,osc.height/2);
	oscCtx.stroke();
};
drawosc();

// Spectroscope
var spc = document.getElementById('spectroscope');
var spcCtx = spc.getContext('2d');
spcCtx.clearRect(0,0,spc.width,spc.height);

function drawspc(){
	drawVisual = requestAnimationFrame(drawspc);

	analyser.getByteFrequencyData(dataArray);
	spcCtx.fillStyle = 'rgb(0,0,0)';
	spcCtx.fillRect(0,0,spc.width,spc.height);
	
	var barWidth = (spc.width / bufferLength) * 2.5;
	var barHeight;
	var x = 0;

	for(var i =0; i < bufferLength; i++){
		barHeight = dataArray[i]/2;
		spcCtx.fillStyle = 'rgb(255,150,0)';
		spcCtx.fillRect(x,spc.height - barHeight/2,barWidth,barHeight);
		x += barWidth +1;
	}
};
drawspc();