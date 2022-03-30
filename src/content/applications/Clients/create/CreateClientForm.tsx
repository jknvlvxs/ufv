import { yupResolver } from '@hookform/resolvers/yup';
import PublishTwoToneIcon from '@mui/icons-material/PublishTwoTone';
import { DatePicker } from '@mui/lab';
import {
  Alert,
  Button,
  Card,
  CardContent,
  CardHeader,
  Divider,
  Grid,
  InputAdornment,
  Snackbar,
  TextField,
} from '@mui/material';
import FormControl from '@mui/material/FormControl';
import FormControlLabel from '@mui/material/FormControlLabel';
import FormLabel from '@mui/material/FormLabel';
import Radio from '@mui/material/Radio';
import RadioGroup from '@mui/material/RadioGroup';
import * as React from 'react';
import { useEffect, useState } from 'react';
import { SubmitHandler, useForm } from 'react-hook-form';
import { IMaskInput } from 'react-imask';
import { useNavigate } from 'react-router-dom';
import { Client } from 'src/models/client';
import { create } from 'src/services/client';
import Guarantor from './Guarantor';
import JuridicalPerson from './JuridicalPerson';
import PhysicalPerson from './PhysicalPerson';
import References from './References';
import Validation from './validation';

const schema = Validation.schema;

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

function CreateClientForm() {
  const navigate = useNavigate();

  const onSubmit: SubmitHandler<Client> = (data) => {
    let obj = Object.keys(data)
      .filter((k) => data[k] !== '' && data[k] !== null)
      .reduce((a, k) => ({ ...a, [k]: data[k] }), {});

    let formData = new FormData();

    Object.keys(obj).forEach((key) => formData.append(key, obj[key]));

    create(formData).then((res) => {
      setOpenConfirm(false);
      return navigate('/management/clients/');
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
  } = useForm<Client>({ resolver: yupResolver(schema) });

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
          <CardHeader title="Cadastrar" subheader="Informe os dados abaixo" />
          <Divider />
          <CardContent>
            <Grid
              container
              component="form"
              noValidate
              autoComplete="off"
              spacing={2}
            >
              <Grid item md={6} xs={12}>
                <FormControl required>
                  <FormLabel id="personValueLabel">
                    Proposta para locação de pessoa:
                  </FormLabel>
                  <RadioGroup
                    defaultValue="physical"
                    row
                    aria-labelledby="personValueLabel"
                    name="position"
                    onChange={(event) =>
                      setValue('personValue', event.target.value)
                    }
                  >
                    <FormControlLabel
                      value="physical"
                      control={<Radio />}
                      label="Pessoa física"
                      labelPlacement="top"
                    />
                    <FormControlLabel
                      value="juridical"
                      control={<Radio />}
                      label="Pessoa jurídica"
                      labelPlacement="top"
                    />
                  </RadioGroup>
                </FormControl>
              </Grid>
              <Grid item md={6} xs={12}>
                <FormControl required>
                  <FormLabel id="guarantorValueLabel">Com fiador:</FormLabel>
                  <RadioGroup
                    defaultValue="no"
                    row
                    aria-labelledby="guarantorValueLabel"
                    name="position"
                    onChange={(event) =>
                      setValue('guarantorValue', event.target.value)
                    }
                  >
                    <FormControlLabel
                      value="yes"
                      control={<Radio />}
                      label="Sim"
                      labelPlacement="top"
                    />
                    <FormControlLabel
                      value="no"
                      control={<Radio />}
                      label="Não"
                      labelPlacement="top"
                    />
                  </RadioGroup>
                </FormControl>
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
                  fullWidth
                  error={!!errors?.goal}
                  helperText={errors?.goal?.message || ''}
                  label="Finalidade"
                  required
                  onChange={(event) => setValue('goal', event.target.value)}
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
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
                  fullWidth
                  error={!!errors?.rentValue}
                  helperText={errors?.rentValue?.message || ''}
                  value={watch('rentValue') || ''}
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
                  fullWidth
                  style={{ width: '100%' }}
                  error={!!errors?.readjustment}
                  helperText={errors?.readjustment?.message || ''}
                  value={watch('readjustment') || ''}
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
                  fullWidth
                  multiline
                  rows={4}
                  error={!!errors?.comments}
                  label="Observações"
                  onChange={(event) => setValue('comments', event.target.value)}
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <FormControl required>
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
                <FormControl required>
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
                <FormControl required>
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
      {(watch('personValue') !== 'juridical' && (
        <PhysicalPerson
          register={register}
          errors={errors}
          setValue={setValue}
          watch={watch}
        />
      )) || (
        <JuridicalPerson
          register={register}
          errors={errors}
          setValue={setValue}
          watch={watch}
        />
      )}
      <References
        register={register}
        errors={errors}
        setValue={setValue}
        watch={watch}
      />
      {watch('guarantorValue') === 'yes' && (
        <Guarantor
          register={register}
          errors={errors}
          setValue={setValue}
          watch={watch}
        />
      )}

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

export default CreateClientForm;
