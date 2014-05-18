var charList = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()/"
var password = ''

function generatePW(pwLength)
{
	password = ''
	for(var i = 0; i < pwLength; i++)
	{
		password += charList.charAt(Math.floor(Math.random() * charList.length))
	}
	return password
}

function generateOutput(enteredLength)
{
	document.pwGenerate.output.value = generatePW(enteredLength)
}

