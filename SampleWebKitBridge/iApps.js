var bosch = new Object();

bosch.sayHello = function (success, failure,data)
{
	boschInternal.sigSuccess.connect(success);
	boschInternal.sigFailure.connect(failure);
	var returnVal = boschInternal.sayHello(data);
	boschInternal.sigSuccess.disconnect(success);
	boschInternal.sigFailure.disconnect(failure);
	return returnVal;
}
