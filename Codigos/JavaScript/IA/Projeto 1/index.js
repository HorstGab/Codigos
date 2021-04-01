Cores = ['#008000', '#FF8C00', '#8b0000', '#191970','#C71585']

/*
    O(1)
*/
function colorirEstado(nomeEstado, cor){
    elem = document.querySelector(`#${nomeEstado}`)
    elem.style.fill = Cores[cor];
}

/* function showDesempenho(numNode){
    elem = document.getElementById('.resultado').innerHTML(numNode);
} 
  */
