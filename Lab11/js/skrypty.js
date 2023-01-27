document.addEventListener('DOMContentLoaded', () => {
    var bglowna = document.getElementById('index');
    bglowna.addEventListener('click',()=>{
        pokazGlowna();
    });

    var bonas = document.getElementById('onas');
    bonas.addEventListener("click", () => {
        console.log("Strona O nas");
        pokazOnas();
    });

    var bgaleria = document.getElementById('galeria');
    bgaleria.addEventListener("click", () => {
        console.log("Galeria zdjęć");
        pokazGalerie();
    });
    
    var bformularz = document.getElementById('formularz');
    bformularz.addEventListener('click',()=>{
        pokazFormularz();
    });
});

pokazGlowna();

function pokazGlowna() {
    fetch("http://localhost:3000/Lab11/skrypty/glowna.php")
        .then((response) => {
            if (response.status !== 200) {
                return Promise.reject('Coś poszło nie tak!');
            }
            return response.text();
        })
        .then((data) => {
            document.getElementById('main').innerHTML=data;
        })
        .catch((error) => {
            console.log(error);
        });
}

function pokazOnas() {
    fetch("http://localhost:3000/Lab11/skrypty/onas.php")
        .then((response) => {
            if (response.status !== 200) {
                return Promise.reject('Coś poszło nie tak!');
            }
            return response.text();
            })
        .then((data) => {
            document.getElementById('main').innerHTML=data;
        })
        .catch((error) => {
            console.log(error);
        });
}

function pokazGalerie() {
    fetch("http://localhost:3000/Lab11/skrypty/galeria.php")
        .then((response) => {
            if (response.status !== 200) {
                return Promise.reject('Coś poszło nie tak!');
            }
            return response.text();
        })
        .then((data) => {
            document.getElementById('main').innerHTML=data;
        })
        .catch((error) => {
            console.log(error);
        });
}

function pokazFormularz() {
    fetch("http://localhost:3000/Lab11/skrypty/formularz.php")
        .then((response) => {
            if (response.status !== 200) {
                return Promise.reject('Coś poszło nie tak!');
            }
            return response.text();
        })
        .then((data) => {
            document.getElementById('main').innerHTML=data;
            var bform = document.querySelector('form');
            console.log(bform);
            bform.addEventListener('submit',processForm);
        })
        .catch((error) => {
            console.log(error);
        });
}

function processForm(event){
    event.preventDefault();
    var formData = new FormData(this);

    fetch("http://localhost:3000/Lab11/skrypty/formProcess.php",formData)
        .then((response) => {
            if (response.status !== 200) {
                return Promise.reject('Coś poszło nie tak!');
            }
            console.log(response);
            return response.text();
        })
        .then((data) => {
            console.log(data);
            document.getElementById('content').innerHTML=data;
        })
        .catch((error) => {
            console.log(error);
        });
}