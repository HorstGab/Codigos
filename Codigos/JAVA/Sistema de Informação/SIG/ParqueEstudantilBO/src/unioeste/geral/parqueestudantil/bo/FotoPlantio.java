package unioeste.geral.parqueestudantil.bo;

public class FotoPlantio {

    private int id;
    private Byte[] foto;
    private Plantio plantio;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Byte[] getFoto() {
        return foto;
    }

    public void setFoto(Byte[] foto) {
        this.foto = foto;
    }

    public Plantio getPlantio() {
        return plantio;
    }

    public void setPlantio(Plantio plantio) {
        this.plantio = plantio;
    }
}
