<details> <summary>Haz clic para ver el código Mermaid</summary>
  classDiagram
    class ReproductorAudio {
        reproducir()
    }
    class ReproductorVideo {
        mostrar()
    }
    class ReproductorMultimedia

    ReproductorMultimedia --|> ReproductorAudio
    ReproductorMultimedia --|> ReproductorVideo
    </details>
