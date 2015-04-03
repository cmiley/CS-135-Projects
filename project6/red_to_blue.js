	var width = 500;
	var height = 375;

	var canvas = document.getElementById('myCanvas');
	var context = canvas.getContext('2d');
	context.fillStyle="rgb(0,0,255)";


	// load image from data url
	var imageObj = new Image();
	imageObj.onload = function() {
		context.drawImage(this, 0, 0);
	};

	imageObj.src = "red-balloons.jpg";

for( var x = 0; x < 700; x++)
{
	for( var y = 0; y < 700; y++)
	{
		context.fillRect( x, y, 1, 1  );
	}
}

document.getElementById('file').onchange = function()
{
	var file = this.files[0];
	var reader = new FileReader();
	reader.onload = function(progressEvent){
    	// Entire file
		// By lines
		var lines = this.result.split('\n');
		for(var line = 0; line < lines.length; line++){
			var rowcol = lines[line].split(' ');
			var row = rowcol[0]; // the row of the pixel
			var col = rowcol[1]; // the column of the pixel
			context.fillStyle="rgb(0,0,255)";
			for( var i = 0; i < lines; i+=2)
			{
				context.fillRect( rowcol[i], rowcol[i+1], 1, 1  );
			}
		}
	};
	reader.readAsText(file);
};
