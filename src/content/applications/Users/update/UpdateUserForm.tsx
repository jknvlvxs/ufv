import { yupResolver } from '@hookform/resolvers/yup';
import PublishTwoToneIcon from '@mui/icons-material/PublishTwoTone';
import {
  Alert,
  Button,
  Card,
  CardContent,
  CardHeader,
  Container,
  Divider,
  FormControl,
  FormHelperText,
  FormLabel,
  Grid,
  MenuItem,
  Select,
  Snackbar,
  TextField,
} from '@mui/material';
import { useEffect, useState } from 'react';
import { SubmitHandler, useForm } from 'react-hook-form';
import { useNavigate } from 'react-router-dom';
import { Users, UsersRoles } from 'src/models/users';
import { update } from 'src/services/users';
import * as yup from 'yup';

const schema = yup.object().shape({
  name: yup.string().required('É obrigatório informar um nome para o usuário'),
  email: yup
    .string()
    .email()
    .required('É obrigatório informar um email para o usuário'),
  role: yup
    .string()
    .required('É obrigatório informar uma função para o usuário'),
  password: yup.string(),
  confirmPassword: yup.string(),
});

function UpdateUserForm(user: Users) {
  const navigate = useNavigate();

  const onSubmit: SubmitHandler<Users> = (data) => {
    const { password, confirmPassword, ...create } = data;
    update(
      user.id,
      password === undefined ? create : { ...create, password }
    ).then((res) => {
      setOpenConfirm(false);
      return navigate('/users/');
    });
  };

  const [openErrors, setOpenErrors] = useState(false);
  const [openConfirm, setOpenConfirm] = useState(false);

  const {
    register,
    setValue,
    handleSubmit,
    watch,
    formState: { errors },
  } = useForm<Users>({ resolver: yupResolver(schema) });

  useEffect(() => {
    register('name');
    register('email');
    register('role');
    register('password');
    register('confirmPassword');
  }, [register]);

  useEffect(() => {
    setValue('name', user.name);
    setValue('email', user.email);
    setValue('role', user.role);
  }, [setValue, user]);

  return (
    <Container>
      <Grid
        container
        direction="row"
        justifyContent="center"
        alignItems="stretch"
        spacing={3}
      >
        <Grid item xs={12}>
          <Card>
            <CardHeader
              title="Cadastrar Usuário"
              subheader="Altere os dados do usuário do sistema."
            />
            <Divider />
            <CardContent>
              <Grid
                container
                component="form"
                noValidate
                autoComplete="on"
                spacing={2}
              >
                <Grid item md={6} xs={12}>
                  <TextField
                    type="name"
                    name="name"
                    value={watch().name || ''}
                    fullWidth
                    error={!!errors?.name}
                    helperText={errors?.name?.message || ''}
                    label="Nome Completo"
                    required
                    onChange={(event) => setValue('name', event.target.value)}
                  />
                </Grid>

                <Grid item md={6} xs={12}>
                  <TextField
                    type="email"
                    name="email"
                    value={watch().email || ''}
                    fullWidth
                    error={!!errors?.email}
                    helperText={errors?.email?.message || ''}
                    label="E-mail"
                    required
                    onChange={(event) => setValue('email', event.target.value)}
                  />
                </Grid>
                <Grid item md={8} xs={12}>
                  <FormControl required fullWidth error={!!errors?.role}>
                    <FormLabel id="roleLabel" children="Função do usuário:" />
                    <Select
                      labelId="demo-simple-select-label"
                      id="demo-simple-select"
                      fullWidth
                      value={watch().role || ''}
                      label="Função"
                      onChange={(event) =>
                        setValue('role', event.target.value as UsersRoles)
                      }
                    >
                      <MenuItem value="user" children="Usuário" />
                      <MenuItem value="admin" children="Administrador" />
                    </Select>
                    <FormHelperText children={errors?.role?.message || ''} />
                  </FormControl>
                </Grid>
              </Grid>
            </CardContent>
          </Card>
        </Grid>
        <Grid item xs={12}>
          <Card>
            <CardHeader
              title="Autenticação"
              subheader="Altere a senha que o usuário utilizará para se autenticar no sistema."
            />
            <Divider />
            <CardContent>
              <Grid
                container
                component="form"
                noValidate
                autoComplete="on"
                spacing={2}
              >
                <Grid item md={6} xs={12}>
                  <TextField
                    type="password"
                    name="password"
                    fullWidth
                    error={!!errors?.password}
                    helperText={errors?.password?.message || ''}
                    label="Senha"
                    onChange={(event) =>
                      setValue('password', event.target.value)
                    }
                  />
                </Grid>
                <Grid item md={6} xs={12}>
                  <TextField
                    type="password"
                    name="password"
                    fullWidth
                    error={!!errors?.confirmPassword}
                    helperText={errors?.confirmPassword?.message || ''}
                    label="Confirmar Senha"
                    onChange={(event) =>
                      setValue('confirmPassword', event.target.value)
                    }
                  />
                </Grid>
              </Grid>
            </CardContent>
          </Card>
        </Grid>
        <Grid item xs={12}>
          <Button
            style={{ float: 'right', marginTop: 10 }}
            disabled={openConfirm}
            sx={{ mt: { xs: 2, md: 0 } }}
            variant="contained"
            onClick={() => handleSubmit(onSubmit)() && setOpenErrors(true)}
            startIcon={<PublishTwoToneIcon fontSize="small" />}
            children="Salvar"
          />
          <Snackbar
            open={Object.keys(errors).length !== 0 && openErrors}
            autoHideDuration={6000}
            onClose={() => setOpenErrors(false)}
            children={
              <Alert
                onClose={() => setOpenErrors(false)}
                severity="error"
                sx={{ width: '100%' }}
                children="Ocorreu um erro ao editar o usuário!"
              />
            }
          />
        </Grid>
      </Grid>
    </Container>
  );
}

export default UpdateUserForm;
