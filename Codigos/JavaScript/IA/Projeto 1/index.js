Cores = ['#008000', '#FF8C00', '#8b0000', '#191970','#C71585']

function colorirEstado(nomeEstado, cor){
    elem = document.querySelector(`#${nomeEstado}`)
    elem.style.fill = Cores[cor];
}

/* function init (){
    let graph = initGraph();

    graph.vertices.forEach(function(node){
        console.log(graph.vertices[node], graph.color[node]);
        colorirEstado(graph.vertices[node], graph.color[node]);
    });

}
 
init(); */

/* colorirEstado('AL', 3)
colorirEstado('RS', 2)
colorirEstado('SC', 4)
colorirEstado('PR', 0)
colorirEstado('SP', 1)
colorirEstado('MS', 3) */