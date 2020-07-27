open Types;

//TODO: feel like this bit should be in Http
let errorMessage = x => Obj.magic(x);

//TODO: would be nice to kill self
//TODO: at the very least make it just send
let load = self =>
  Http.get(
    self,
    "http://localhost:8080/counter",
    text => RequestSuccess(int_of_string(text)),
    error => RequestFailure(errorMessage(error)),
  );

let increment = self =>
  Http.post(
    self,
    "http://localhost:8080/increment",
    text => RequestSuccess(int_of_string(text)),
    error => RequestFailure(errorMessage(error)),
  );

let decrement = self =>
  Http.post(
    self,
    "http://localhost:8080/decrement",
    text => RequestSuccess(int_of_string(text)),
    error => RequestFailure(errorMessage(error)),
  );