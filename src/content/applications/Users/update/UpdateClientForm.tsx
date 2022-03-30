import {
  Alert,
  Button,
  Card,
  CardContent,
  CardHeader,
  Divider,
  FormControl,
  FormLabel,
  Grid,
  InputAdornment,
  Snackbar,
  TextField,
} from '@mui/material';
import Text from 'src/components/Text';

import * as React from 'react';
import { IMaskInput } from 'react-imask';
import PublishTwoToneIcon from '@mui/icons-material/PublishTwoTone';
import { useNavigate } from 'react-router-dom';
import { Client } from 'src/models/client';
import { SubmitHandler, useForm } from 'react-hook-form';
import { yupResolver } from '@hookform/resolvers/yup';
import { update } from 'src/services/client';
import { useEffect, useState } from 'react';
import { DatePicker } from '@mui/lab';

const schema = null;

interface MoneyCustomProps {
  onChange: (event: { target: { money: string; value: string } }) => void;
  money: string;
}

const MoneyMaskCustom = React.forwardRef<HTMLElement, MoneyCustomProps>(
  (props, ref) => {
    const { onChange, ...other } = props;
    return (
      <IMaskInput
        {...other}
        mask={Number}
        scale={2}
        signed={false}
        thousandsSeparator={'.'}
        padFractionalZeros={true}
        normalizeZeros={true}
        radix={','}
        mapToRadix={['.']}
        onAccept={(value: any) =>
          onChange({ target: { money: props.money, value } })
        }
        unmask={true}
      />
    );
  }
);

function UpdateClientForm(client) {
  const navigate = useNavigate();

  const onSubmit: SubmitHandler<Client> = (data) => {
    let obj = Object.keys(data)
      .filter(
        (k) => data[k] !== '' && data[k] !== null && data[k] !== undefined
      )
      .reduce((a, k) => ({ ...a, [k]: data[k] }), {});

    let formData = new FormData();
    Object.keys(obj).forEach((key) => formData.append(key, obj[key]));

    update(client.id, formData).then((response) => {
      if (response.status === 200) {
        setOpenConfirm(false);
        return navigate('/clients/');
      } else {
        alert('Houve um erro!');
      }
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
  } = useForm({ resolver: yupResolver(schema) });

  useEffect(() => {
    register('personValue');
    register('guarantorValue');
    register('goal');
    register('propertyCode');
    register('propertyAddress');
    register('district');
    register('ownerName');
    register('rentValue');
    register('deadline');
    register('readjustment');
    register('startDate');
    register('finishDate');
    register('comments');
    register('documentFile');
    register('receiptAddress');
    register('receiptIncome');
  }, [register]);

  useEffect(() => {
    setValue('personValue', client.personValue);
    setValue('guarantorValue', client.guarantorValue);
    setValue('goal', client.goal);
    setValue('propertyCode', client.propertyCode);
    setValue('propertyAddress', client.propertyAddress);
    setValue('district', client.district);
    setValue('ownerName', client.ownerName);
    setValue('rentValue', client.rentValue);
    setValue('deadline', client.deadline);
    setValue('readjustment', client.readjustment);
    setValue('startDate', client.startDate);
    setValue('finishDate', client.finishDate);
    setValue('comments', client.comments);
  }, [setValue, client]);

  return (
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
            title="Cadastrar"
            subheader="Altere os dados que desejar e confirme"
          />
          <Divider />
          <CardContent>
            <Grid
              container
              component="form"
              noValidate
              autoComplete="off"
              spacing={2}
            >
              <Grid item xs={12} sm={12} md={12}>
                <Text color="black">
                  <label>Tipo de pessoa: </label>
                  <b>
                    {client.personValue === 'juridical'
                      ? 'Jurídica.'
                      : 'Física.'}
                  </b>
                </Text>
              </Grid>

              <Grid item xs={12} sm={12} md={12} mb={2}>
                <Text color="black">
                  <label>Fiador: </label>
                  <b>{client.guarantorValue === 'yes' ? 'Sim.' : 'Não.'}</b>
                </Text>
              </Grid>
            </Grid>
          </CardContent>
        </Card>
      </Grid>
      <Grid item xs={12}>
        <Card>
          <CardHeader title="Dados do imóvel" />
          <Divider />
          <CardContent>
            <Grid
              container
              component="form"
              noValidate
              autoComplete="off"
              spacing={2}
            >
              <Grid item md={8} xs={12}>
                <TextField
                  value={watch().goal || ''}
                  fullWidth
                  error={!!errors?.goal}
                  helperText={errors?.goal?.message || ''}
                  label="Finalidade"
                  required
                  onChange={(event) => setValue('goal', event.target.value)}
                />
              </Grid>
              <Divider />

              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().propertyCode || ''}
                  fullWidth
                  error={!!errors?.propertyCode}
                  helperText={errors?.propertyCode?.message || ''}
                  label="Código do imóvel"
                  required
                  onChange={(event) =>
                    setValue('propertyCode', event.target.value)
                  }
                />
              </Grid>

              <Grid item md={8} xs={12}>
                <TextField
                  value={watch().propertyAddress || ''}
                  fullWidth
                  error={!!errors?.propertyAddress}
                  helperText={errors?.propertyAddress?.message || ''}
                  label="Endereço do imóvel"
                  required
                  onChange={(event) =>
                    setValue('propertyAddress', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().district || ''}
                  fullWidth
                  error={!!errors?.district}
                  helperText={errors?.district?.message || ''}
                  label="Bairro"
                  required
                  onChange={(event) => setValue('district', event.target.value)}
                />
              </Grid>

              <Grid item md={12} xs={12}>
                <TextField
                  value={watch().ownerName || ''}
                  fullWidth
                  error={!!errors?.ownerName}
                  helperText={errors?.ownerName?.message || ''}
                  label="Nome do proprietário"
                  required
                  onChange={(event) =>
                    setValue('ownerName', event.target.value)
                  }
                />
              </Grid>

              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().rentValue || ''}
                  fullWidth
                  error={!!errors?.rentValue}
                  helperText={errors?.rentValue?.message || ''}
                  label="Valor do aluguel"
                  required
                  onChange={(event) =>
                    setValue('rentValue', event.target.value)
                  }
                  InputProps={{
                    inputComponent: MoneyMaskCustom as any,
                    startAdornment: (
                      <InputAdornment position="start">R$</InputAdornment>
                    ),
                  }}
                />
              </Grid>

              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().deadline || ''}
                  fullWidth
                  error={!!errors?.deadline}
                  helperText={errors?.deadline?.message || ''}
                  label="Prazo"
                  required
                  onChange={(event) => setValue('deadline', event.target.value)}
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().readjustment || ''}
                  fullWidth
                  style={{ width: '100%' }}
                  error={!!errors?.readjustment}
                  helperText={errors?.readjustment?.message || ''}
                  label="Reajuste"
                  required
                  onChange={(event) =>
                    setValue('readjustment', event.target.value)
                  }
                  InputProps={{
                    inputComponent: MoneyMaskCustom as any,
                    startAdornment: (
                      <InputAdornment position="start">R$</InputAdornment>
                    ),
                  }}
                />
              </Grid>

              <Grid item md={6} xs={12}>
                <DatePicker
                  label="Data de início"
                  value={watch().startDate || null}
                  onChange={(date) => {
                    setValue('startDate', date);
                  }}
                  renderInput={(params) => (
                    <TextField
                      fullWidth
                      required
                      {...params}
                      error={!!errors?.startDate}
                      helperText={errors?.startDate?.message || ''}
                    />
                  )}
                  inputFormat="dd/MM/yyyy"
                />
              </Grid>
              <Grid item md={6} xs={12}>
                <DatePicker
                  label="Data de término"
                  value={watch().finishDate || null}
                  onChange={(date) => {
                    setValue('finishDate', date);
                  }}
                  renderInput={(params) => (
                    <TextField
                      fullWidth
                      style={{ width: '100%' }}
                      required
                      {...params}
                      error={!!errors?.finishDate}
                    />
                  )}
                  inputFormat="dd/MM/yyyy"
                />
              </Grid>

              <Grid item md={12} xs={12}>
                <TextField
                  value={watch().comments || ''}
                  fullWidth
                  multiline
                  rows={4}
                  error={!!errors?.comments}
                  label="Observações"
                  onChange={(event) => setValue('comments', event.target.value)}
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <FormControl>
                  <FormLabel>Xerox do RG e CPF:</FormLabel>
                  <TextField
                    error={!!errors?.documentFile}
                    helperText={errors?.documentFile?.message || ''}
                    id="documentFile"
                    name="documentFile"
                    type="file"
                    required
                    onChange={(event) => {
                      setValue(
                        'documentFile',
                        (event.target as HTMLInputElement).files[0]
                      );
                    }}
                  />
                </FormControl>
              </Grid>
              <Grid item md={4} xs={12}>
                <FormControl>
                  <FormLabel>Comprovante de residência:</FormLabel>
                  <TextField
                    error={!!errors?.receiptAddress}
                    helperText={errors?.receiptAddress?.message || ''}
                    id="receiptAddress"
                    name="receiptAddress"
                    type="file"
                    onChange={(event) => {
                      setValue(
                        'receiptAddress',
                        (event.target as HTMLInputElement).files[0]
                      );
                    }}
                  />
                </FormControl>
              </Grid>
              <Grid item md={4} xs={12}>
                <FormControl>
                  <FormLabel>Comprovante de renda:</FormLabel>
                  <TextField
                    error={!!errors?.receiptIncome}
                    helperText={errors?.receiptIncome?.message || ''}
                    id="receiptIncome"
                    name="receiptIncome"
                    type="file"
                    onChange={(event) => {
                      setValue(
                        'receiptIncome',
                        (event.target as HTMLInputElement).files[0]
                      );
                    }}
                  />
                </FormControl>
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
        >
          Salvar
        </Button>

        <Snackbar
          open={Object.keys(errors).length !== 0 && openErrors}
          autoHideDuration={6000}
          onClose={() => setOpenErrors(false)}
        >
          <Alert
            onClose={() => setOpenErrors(false)}
            severity="error"
            sx={{ width: '100%' }}
          >
            Verifique se todos os campos obrigatórios foram preenchidos!
          </Alert>
        </Snackbar>
      </Grid>
    </Grid>
  );
}

export default UpdateClientForm;
