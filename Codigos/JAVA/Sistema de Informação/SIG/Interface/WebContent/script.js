
class Validator{
    constructor(){
        this.validations = [

        ]
    }

    //iniciar a validação dos campos
    validate(form){
        //pegar os inputs
        let inputs = form.getElementByTagName('input');

        console.log(inputs);
        //htmlCollection -> Array
        let inputA rray = [...inputs];
         
        console.log(inputArray);
    }
}



let form  = document.getElementById("register-form");
let submit = document.getElementById("btn-submit");
let Validator = new  Validator();

//evento que dispara as validações
submit.addEventListener('click', function(e){

    e.preventDefault();
    Validator.validate(form); 
})