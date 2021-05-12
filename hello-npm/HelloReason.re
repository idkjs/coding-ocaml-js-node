Js.log("Hello, Reason!")
Lib.log("Hello, Log")
Hello.sayHello

open MomentRe;
Js.log(moment("2017-01-01") |> Moment.clone |> Moment.isValid ==true)
open OcamlRe;
let rawOutput = ref(false);
