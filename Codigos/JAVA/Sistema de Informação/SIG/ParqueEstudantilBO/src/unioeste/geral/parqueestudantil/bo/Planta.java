package unioeste.geral.parqueestudantil.bo;

public class Planta {

    private int id;
    private String nomeComum;
    private String nomeCientifico;
    private Aluno aluno;
    private Plantio plantio;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNomeComum() {
        return nomeComum;
    }

    public void setNomeComum(String nomeComum) {
        this.nomeComum = nomeComum;
    }

    public String getNomeCientifico() {
        return nomeCientifico;
    }

    public void setNomeCientifico(String nomeCientifico) {
        this.nomeCientifico = nomeCientifico;
    }

    public Aluno getAluno() {
        return aluno;
    }

    public void setAluno(Aluno aluno) {
        this.aluno = aluno;
    }

    public Plantio getPlantio() {
        return plantio;
    }

    public void setPlantio(Plantio plantio) {
        this.plantio = plantio;
    }
}
