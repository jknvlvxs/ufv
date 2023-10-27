const objetos = {
  insercao: document.getElementById("insercao"),
  pendentes: document.getElementById("lista-pendentes"),
  fazendo: document.getElementById("lista-fazendo"),
  concluidas: document.getElementById("lista-concluidas"),
  btnAdd: document.getElementById("btnNova"),
  input: document.getElementById("nova"),
  btnClear: document.getElementById("btnLimpa"),
  tarefaArrastada: null,
};

objetos.btnAdd.addEventListener("click", insere);
objetos.btnClear.addEventListener("click", limpa);

objetos.input.addEventListener("keyup", (event) => {
  if (event.key === "Enter") insere();
});

function insere() {
  let texto = objetos.input.value;

  if (!texto) {
    alert("Informe um texto para a tarefa");
  } else {
    let card = criaTarefa(texto, "pendente");
    objetos.pendentes.appendChild(card);
    objetos.input.value = "";
    objetos.input.focus();
  }
}

function limpa() {
  objetos.input.value = "";
  objetos.input.focus();
}

function criaTarefa(texto, classe) {
  let div = document.createElement("div");
  div.classList.add("card");
  div.classList.add(classe);

  let sp = document.createElement("span");
  sp.appendChild(document.createTextNode(texto));
  sp.classList.add("tarefa");

  div.appendChild(sp);

  div.setAttribute("draggable", true);
  div.addEventListener("dragstart", (event) => {
    objetos.tarefaArrastada = div;
    event.dataTransfer.effectAllowed = "move";
    let texto = div.querySelector("span").innerText;
    event.dataTransfer.setData("text", texto);
    div.classList.add("dragging");
  });

  div.addEventListener("dragend", (event) => {
    objetos.tarefaArrastada = null;
    div.classList.remove("dragging");
  });

  return div;
}

objetos.pendentes.addEventListener("dragover", (event) => {
  event.preventDefault();
  event.dataTransfer.dropEffect = "move";
  objetos.pendentes.classList.add("dragover");
});

objetos.pendentes.addEventListener("dragleave", () => {
  objetos.pendentes.classList.remove("dragover");
});

objetos.pendentes.addEventListener("drop", (event) => {
  event.preventDefault();
  let texto = event.dataTransfer.getData("text");
  let novoItem = criaTarefa(texto, "pendente");
  objetos.pendentes.appendChild(novoItem);
  objetos.tarefaArrastada.parentNode.removeChild(objetos.tarefaArrastada);
  objetos.pendentes.classList.remove("dragover");
});

objetos.fazendo.addEventListener("dragover", (event) => {
  event.preventDefault();
  event.dataTransfer.dropEffect = "move";
  objetos.fazendo.classList.add("dragover");
});

objetos.fazendo.addEventListener("dragleave", () => {
  objetos.fazendo.classList.remove("dragover");
});

objetos.fazendo.addEventListener("drop", (event) => {
  event.preventDefault();
  let texto = event.dataTransfer.getData("text");
  let novoItem = criaTarefa(texto, "fazendo");
  objetos.fazendo.appendChild(novoItem);
  objetos.tarefaArrastada.parentNode.removeChild(objetos.tarefaArrastada);
  objetos.fazendo.classList.remove("dragover");
});

objetos.concluidas.addEventListener("dragover", (event) => {
  event.preventDefault();
  event.dataTransfer.dropEffect = "move";
  objetos.concluidas.classList.add("dragover");
});

objetos.concluidas.addEventListener("dragleave", () => {
  objetos.concluidas.classList.remove("dragover");
});

objetos.concluidas.addEventListener("drop", (event) => {
  event.preventDefault();
  let texto = event.dataTransfer.getData("text");
  let novoItem = criaTarefa(texto, "concluida");
  objetos.concluidas.appendChild(novoItem);
  objetos.tarefaArrastada.parentNode.removeChild(objetos.tarefaArrastada);
  objetos.concluidas.classList.remove("dragover");
});

objetos.insercao.addEventListener("dragover", (event) => {
  event.preventDefault();
  event.dataTransfer.dropEffect = "move";
  objetos.insercao.classList.add("dragover");
});

objetos.insercao.addEventListener("dragleave", () => {
  objetos.insercao.classList.remove("dragover");
});

objetos.insercao.addEventListener("drop", (event) => {
  event.preventDefault();
  let texto = event.dataTransfer.getData("text");
  objetos.input.value = texto;
  objetos.input.focus();
  objetos.tarefaArrastada.parentNode.removeChild(objetos.tarefaArrastada);
  objetos.insercao.classList.remove("dragover");
});
