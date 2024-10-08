var express = require('express');
var router = express.Router();

const usuario = require('../models/usuario');
const config = require('../config/config');
const utils = require('../utils/utils');

// Se houver tentativa de acesso direto via get
router.get('/', (req, res, next) => {
  res.render('index', {
    title: config.title,
    header: config.indexHeader
  });
});

// Requisição via post do formulário
router.post('/', (req, res) => {
  (async () => {
    try {
      const login = req.body.login;
      const senha = req.body.senha;

      let mensagem;

      let id = await usuario.getId(login);
      
      if (!id) {
        mensagem = `Usuário ${login} inexistente`;
        console.log(mensagem);
        utils.renderizaErro(res, mensagem);
      } else {
        let valido = await usuario.autentica(id, senha);
        if (!valido) {
          mensagem = `Senha incorreta`;
          console.log(mensagem);
          utils.renderizaErro(res, mensagem);
        } else {
          let nome = await usuario.getNome(id);
          let admin = await usuario.superUsuario(id);
          res.cookie('valido', true);
          res.cookie('idUsuario', id);
          if (admin) {
            const dados = {
              title: config.title,
              header: 'Olá ' + nome + '!',
              usuarios: await usuario.lista()
            }
            res.render('lista', dados);
          } else {
            res.redirect('/perfil');
          }
        }
      }

    } catch (erro) {
      utils.renderizaErro(res, erro.message);
    }
  })();
});

module.exports = router;
