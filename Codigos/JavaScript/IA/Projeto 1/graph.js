const TagColor = {
    incolor : 0,
    vermelho : 1,
    verde : 2, 
    azul : 3, 
    amarelo : 4
}

class Graph {
    constructor() {
        this.vertices = [];
        this.edges = [];
        this.color = [];
    }

    addVertex(vertex) {
        this.vertices.push(vertex);
        this.edges[vertex] = [];
        this.color[vertex] = TagColor.incolor;
    }

    addEdge(vertex1, vertex2) {
        this.edges[vertex1].push(vertex2);
        this.edges[vertex2].push(vertex1);        
    }

    size() {
        return this.vertices.length;
    }

    print() {
        console.log(this.vertices.map(vertex => {
            return(`${vertex}[${this.color[vertex]}] [${this.edges[vertex].length}]=> ${this.edges[vertex].join(', ')}`).trim();
        }, this).join('\n'));
    }
}

function initGraph(algortihm) {
    let graph = new Graph();

    graph.addVertex("RS")
    graph.addVertex("SC")
    graph.addVertex("PR")
    graph.addVertex("SP")
    graph.addVertex("MS")
    graph.addVertex("MG")
    graph.addVertex("RJ")
    graph.addVertex("GO")
    graph.addVertex("MT")
    graph.addVertex("ES")
    graph.addVertex("BA")
    graph.addVertex("DF")
    graph.addVertex("TO")
    graph.addVertex("PA")
    graph.addVertex("AM")
    graph.addVertex("RO")
    graph.addVertex("PI")
    graph.addVertex("PE")
    graph.addVertex("AL")
    graph.addVertex("SE")
    graph.addVertex("MA")
    graph.addVertex("RR")
    graph.addVertex("AP")
    graph.addVertex("AC")
    graph.addVertex("CE")
    graph.addVertex("PB")
    graph.addVertex("RN")

    graph.addEdge("RS", "SC")
    graph.addEdge("PR", "SC")
    graph.addEdge("PR", "MS")
    graph.addEdge("PR", "SP")
    graph.addEdge("SP", "MS")
    graph.addEdge("SP", "MG")
    graph.addEdge("SP", "RJ")
    graph.addEdge("MS", "MG")
    graph.addEdge("MS", "GO")
    graph.addEdge("MS", "MT")
    graph.addEdge("MG", "RJ")
    graph.addEdge("MG", "GO")
    graph.addEdge("MG", "ES")
    graph.addEdge("MG", "BA")
    graph.addEdge("MG", "DF")
    graph.addEdge("RJ", "ES")
    graph.addEdge("GO", "MT")
    graph.addEdge("GO", "TO")
    graph.addEdge("GO", "BA")
    graph.addEdge("GO", "DF")  
    graph.addEdge("MT", "TO")
    graph.addEdge("MT", "PA")  
    graph.addEdge("MT", "AM")
    graph.addEdge("MT", "RO")  
    graph.addEdge("ES", "BA")    
    graph.addEdge("BA", "TO")
    graph.addEdge("BA", "PI")
    graph.addEdge("BA", "PE")
    graph.addEdge("BA", "AL")
    graph.addEdge("BA", "SE")  
    graph.addEdge("TO", "PA")
    graph.addEdge("TO", "MA")
    graph.addEdge("TO", "PI")
    graph.addEdge("PA", "AM")
    graph.addEdge("PA", "RR")
    graph.addEdge("PA", "AP")
    graph.addEdge("PA", "MA")
    graph.addEdge("AM", "AC")
    graph.addEdge("AM", "RO")
    graph.addEdge("AM", "RR")
    graph.addEdge("RO", "AC")
    graph.addEdge("PI", "MA")
    graph.addEdge("PI", "CE")
    graph.addEdge("PI", "PE")
    graph.addEdge("PE", "AL")
    graph.addEdge("PE", "CE")
    graph.addEdge("PE", "PB")
    graph.addEdge("AL", "SE")
    graph.addEdge("CE", "PB")
    graph.addEdge("CE", "RN")
    graph.addEdge("PB", "RN")

    selectAlgorithmColoring(graph, algortihm);
}

function selectAlgorithmColoring(graph, algorithm='defaul'){
    switch(algorithm){
        default:
        case 'forcaBruta':
            forcaBruta(graph)
        break;
        case 'welsh_powell':
            welsh_powell(graph)
        break; 
        case 'reset':
            location.reload()
        break;
    }
}

async function welsh_powell(graph){
    coloração = 1;
    let verticeordenado = ordenacaoGrau(graph);
    let vizinhos = [];
    
    for(let node of verticeordenado){
        if(graph.color[node] === TagColor.incolor){
            vizinhos = graph.edges[node];
            await recursiveWelshPowell(node, verticeordenado, coloração, vizinhos, graph);
            coloração++;
        }
    }
}

function recursiveWelshPowell (node, vertices, coloração, vizinhos, graph){
    if(!vertices.length) return;
    return new Promise((resolve, reject) => {
            let cor = Object.keys(TagColor)[coloração];
            graph.color[node] = coloração;
            colorirEstado(node, graph.color[node]);
            
            let countiesPrime = deleteVizinhos(vertices, vizinhos, graph)
            timeoutNum = setTimeout(() => {
                let value = recursiveWelshPowell(countiesPrime[0], countiesPrime, coloração, graph.edges[countiesPrime[0]],graph);
                resolve(value);
            }, 150);
    });
}

function deleteVizinhos(vertices, vizinhos, graph){
    let newVertice = [];
    let temp = 0;
    for(let i = 0; i < vertices.length; i++){
        for(let j = 0; j < vizinhos.length; j++){
            if(vertices[i] !== vizinhos[j] && graph.color[vertices[i]] === TagColor.incolor){
                temp++;
            }
        }
        if(temp == vizinhos.length) newVertice.push(vertices[i]);
        temp = 0;
    }
    return newVertice;
}

function ordenacaoGrau (graphTemp){
    let indices = graphTemp.vertices;
    indices.sort((a, b) => {
        return graphTemp.edges[a].length < graphTemp.edges[b].length ? 1 : graphTemp.edges[a].length > graphTemp.edges[b].length ? -1 : 0;
    });
    return indices;
}


function checkColor (graph){
    let x = true; 
    graph.vertices.forEach(function(node){
        vizinho = graph.edges[node]; 
        vizinho.forEach(function(node1){
            if(graph.color[node] === graph.color[node1]){ 
                x = false; 
            }
        });
    });
    return x;
}


/* function forcaBruta(graph){
    for(let c = 1; c < )
} */
async function forcaBruta(graph, maxColors=4){
    let isSolucao = false;
    do{
        isSolucao = await forcaBrutaIteracao(graph, maxColors);
    }while(!isSolucao);
    return graph;
}

function forcaBrutaIteracao(graph, maxColors){
    return new Promise((resolve, reject) => {
        timeoutNum = setTimeout(() => {
            let indexes = Object.keys(graph.color);
            let rest = ((graph.color[indexes[0]]+1) % maxColors === 0)? 1:0;
            graph.color[indexes[0]] += 1;
            graph.color[indexes[0]] %= maxColors;

            for(let i = 1; rest && i < graph.vertices.length; i++){
                graph.color[indexes[i]] = rest;
                rest =+ ((graph.color[indexes[i]] + rest) % maxColors === 0);
                graph.color[indexes[i]] %= maxColors;
            }
            
            graph.vertices.forEach((node) => {
                colorirEstado(node, graph.color[node]);
            });
            resolve(checkColor(graph));
        }, 150);
    });
}

function start(alg){
    initGraph(alg)
}
