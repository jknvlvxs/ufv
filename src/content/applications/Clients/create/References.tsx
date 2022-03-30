import { DatePicker } from '@mui/lab';
import {
  Grid,
  TextField,
  Card,
  CardHeader,
  CardContent,
  Divider,
} from '@mui/material';
import * as React from 'react';
import { IMaskInput } from 'react-imask';

import { useEffect } from 'react';

interface PhoneCustomProps {
  onChange: (event: { target: { phone: string; value: string } }) => void;
  phone: string;
}

const PhoneMaskCustom = React.forwardRef<HTMLElement, PhoneCustomProps>(
  (props, ref) => {
    const { onChange, ...other } = props;
    return (
      <IMaskInput
        {...other}
        mask={[{ mask: '(00) 0000-0000' }, { mask: '(00) 00000-0000' }]}
        onAccept={(value: any) =>
          onChange({ target: { phone: props.phone, value } })
        }
        unmask={true}
      />
    );
  }
);

function References({ register, errors, watch, setValue }) {
  useEffect(() => {
    register('othersIncome');
    register('referenceBankName');
    register('referenceBankAgency');
    register('referenceBankAccount');
    register('referenceBankCity');
    register('referenceBankYearOpenAccount');

    register('referenceBankName_2');
    register('referenceBankAgency_2');
    register('referenceBankAccount_2');
    register('referenceBankCity_2');
    register('referenceBankYearOpenAccount_2');

    register('referenceCommercialName');
    register('referenceCommercialAddress');
    register('referenceCommercialPhone');

    register('referenceCommercialName_2');
    register('referenceCommercialAddress_2');
    register('referenceCommercialPhone_2');

    register('referencePersonalName');
    register('referencePersonalAddress');
    register('referencePersonalPhone');

    register('referencePersonalName_2');
    register('referencePersonalAddress_2');
    register('referencePersonalPhone_2');
  }, [register]);

  return (
    <>
      <Grid item xs={12}>
        <Card>
          <CardHeader title="Outras rendas" />
          <Divider />
          <CardContent>
            <Grid
              container
              component="form"
              noValidate
              autoComplete="off"
              spacing={2}
            >
              <Grid item xs={12}>
                <TextField
                  fullWidth
                  multiline
                  rows={2}
                  error={!!errors?.othersIncome}
                  helperText={errors?.othersIncome?.message || ''}
                  label="Quais? Valor?"
                  onChange={(event) =>
                    setValue('othersIncome', event.target.value)
                  }
                />
              </Grid>
            </Grid>
          </CardContent>
        </Card>
      </Grid>

      <Grid item xs={12}>
        <Card>
          <CardHeader title="Referências Bancárias (Banco em que mantêm ou manteve transações)" />
          <Divider />
          <CardContent>
            <Grid
              container
              component="form"
              noValidate
              autoComplete="off"
              spacing={2}
            >
              <Grid item md={2} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referenceBankName}
                  helperText={errors?.referenceBankName?.message || ''}
                  label="Banco"
                  onChange={(event) =>
                    setValue('referenceBankName', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={2} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referenceBankAgency}
                  helperText={errors?.referenceBankAgency?.message || ''}
                  label="Agência"
                  onChange={(event) =>
                    setValue('referenceBankAgency', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={2} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referenceBankAccount}
                  helperText={errors?.referenceBankAccount?.message || ''}
                  label="Conta"
                  onChange={(event) =>
                    setValue('referenceBankAccount', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referenceBankCity}
                  helperText={errors?.referenceBankCity?.message || ''}
                  label="Cidade"
                  onChange={(event) =>
                    setValue('referenceBankCity', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <DatePicker
                  views={['year']}
                  label="Ano da abertura da conta"
                  value={watch().referenceBankYearOpenAccount || ''}
                  onChange={(date) => {
                    setValue('referenceBankYearOpenAccount', date);
                  }}
                  renderInput={(params) => (
                    <TextField
                      fullWidth
                      {...params}
                      error={!!errors?.referenceBankYearOpenAccount}
                      helperText={
                        errors?.referenceBankYearOpenAccount?.message || ''
                      }
                    />
                  )}
                  inputFormat="yyyy"
                  maxDate={new Date()}
                />
              </Grid>

              <Grid item md={2} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referenceBankName_2}
                  helperText={errors?.referenceBankName_2?.message || ''}
                  label="Banco"
                  onChange={(event) =>
                    setValue('referenceBankName_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={2} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referenceBankAgency_2}
                  helperText={errors?.referenceBankAgency_2?.message || ''}
                  label="Agência"
                  onChange={(event) =>
                    setValue('referenceBankAgency_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={2} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referenceBankAccount_2}
                  helperText={errors?.referenceBankAccount_2?.message || ''}
                  label="Conta"
                  onChange={(event) =>
                    setValue('referenceBankAccount_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referenceBankCity_2}
                  helperText={errors?.referenceBankCity_2?.message || ''}
                  label="Cidade"
                  onChange={(event) =>
                    setValue('referenceBankCity_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <DatePicker
                  views={['year']}
                  label="Ano da abertura da conta"
                  value={watch().referenceBankYearOpenAccount_2 || null}
                  onChange={(date) => {
                    setValue('referenceBankYearOpenAccount_2', date);
                  }}
                  renderInput={(params) => (
                    <TextField
                      fullWidth
                      {...params}
                      error={!!errors?.referenceBankYearOpenAccount_2}
                      helperText={
                        errors?.referenceBankYearOpenAccount_2?.message || ''
                      }
                    />
                  )}
                  inputFormat="yyyy"
                  maxDate={new Date()}
                />
              </Grid>
            </Grid>
          </CardContent>
        </Card>
      </Grid>

      <Grid item xs={12}>
        <Card>
          <CardHeader title="Referências Comerciais (Firmas onde já tenha comprado a crédito)" />
          <Divider />
          <CardContent>
            <Grid
              container
              component="form"
              noValidate
              autoComplete="off"
              spacing={2}
            >
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referenceCommercialName}
                  helperText={errors?.referenceCommercialName?.message || ''}
                  label="Nome"
                  required
                  onChange={(event) =>
                    setValue('referenceCommercialName', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referenceCommercialAddress}
                  helperText={errors?.referenceCommercialAddress?.message || ''}
                  label="Endereço"
                  required
                  onChange={(event) =>
                    setValue('referenceCommercialAddress', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referenceCommercialPhone}
                  helperText={errors?.referenceCommercialPhone?.message || ''}
                  label="Telefone"
                  required
                  value={watch('referenceCommercialPhone') || ''}
                  onChange={(event) =>
                    setValue('referenceCommercialPhone', event.target.value)
                  }
                  InputProps={{
                    inputComponent: PhoneMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>

              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referenceCommercialName_2}
                  helperText={errors?.referenceCommercialName_2?.message || ''}
                  label="Nome"
                  required
                  onChange={(event) =>
                    setValue('referenceCommercialName_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referenceCommercialAddress_2}
                  helperText={
                    errors?.referenceCommercialAddress_2?.message || ''
                  }
                  label="Endereço"
                  required
                  onChange={(event) =>
                    setValue('referenceCommercialAddress_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referenceCommercialPhone_2}
                  helperText={errors?.referenceCommercialPhone_2?.message || ''}
                  label="Telefone"
                  required
                  value={watch('referenceCommercialPhone_2') || ''}
                  onChange={(event) =>
                    setValue('referenceCommercialPhone_2', event.target.value)
                  }
                  InputProps={{
                    inputComponent: PhoneMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>
            </Grid>
          </CardContent>
        </Card>
      </Grid>

      <Grid item xs={12}>
        <Card>
          <CardHeader title="Referências pessoais (Citar duas pessoas parentes ou amigas)" />
          <Divider />
          <CardContent>
            <Grid
              container
              component="form"
              noValidate
              autoComplete="off"
              spacing={2}
            >
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referencePersonalName}
                  helperText={errors?.referencePersonalName?.message || ''}
                  label="Nome"
                  required
                  onChange={(event) =>
                    setValue('referencePersonalName', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referencePersonalAddress}
                  helperText={errors?.referencePersonalAddress?.message || ''}
                  label="Endereço"
                  required
                  onChange={(event) =>
                    setValue('referencePersonalAddress', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referencePersonalPhone}
                  helperText={errors?.referencePersonalPhone?.message || ''}
                  label="Telefone"
                  required
                  value={watch('referencePersonalPhone') || ''}
                  onChange={(event) =>
                    setValue('referencePersonalPhone', event.target.value)
                  }
                  InputProps={{
                    inputComponent: PhoneMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>

              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referencePersonalName_2}
                  helperText={errors?.referencePersonalName_2?.message || ''}
                  label="Nome"
                  required
                  onChange={(event) =>
                    setValue('referencePersonalName_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referencePersonalAddress_2}
                  helperText={errors?.referencePersonalAddress_2?.message || ''}
                  label="Endereço"
                  required
                  onChange={(event) =>
                    setValue('referencePersonalAddress_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.referencePersonalPhone_2}
                  label="Telefone"
                  required
                  helperText={errors?.referencePersonalPhone_2?.message || ''}
                  value={watch('referencePersonalPhone_2') || ''}
                  onChange={(event) =>
                    setValue('referencePersonalPhone_2', event.target.value)
                  }
                  InputProps={{
                    inputComponent: PhoneMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>
            </Grid>
          </CardContent>
        </Card>
      </Grid>
    </>
  );
}

export default References;
