
class Validator{
    constructor(){
        this.validations = [
            'data-min-length',
        ]
    }

    //iniciar a validação dos campos
    validate(form){
        //pegar os inputs
        let inputs = form.getElementsByTagName('input');
        

        //transforma htmlCollection -> Array
        let inputsArray = [...inputs];
        
        //loop nos input e validação
        inputsArray.forEach(function(input){

            //loop em todas as validações
            for(let i = 0; this.validations.length > i; i++){
                //verifica se a validação atual existe no input
                if(input.getAttribute(this.validations[i]!==null)){
                    
                    //limpando a string pra virar o nome de um metodo
                    let method = this.validations[i].replace('data-','').replace('-','');

                    //valor do input
                    let value = input.getAttribute(this.validations[i]);

                    //invocar o metodo
                    this[method](input, value);
                }
            }
        }, this)
    }

    //verifica o numero minimo de caracteres
    minlength(input, minValue){
        
    }
}

let form  = document.getElementById("register-form");
let submit = document.getElementById("btn-submit");
let validator = new  Validator();

//evento que dispara as validações
submit.addEventListener('click', function(e){

    e.preventDefault();
    validator.validate(form); 
})

