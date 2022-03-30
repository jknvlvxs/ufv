import {
  Card,
  CardContent,
  CardHeader,
  Divider,
  FormControl,
  Grid,
  InputLabel,
  MenuItem,
  Select,
  TextField,
} from '@mui/material';

import * as React from 'react';
import { IMaskInput } from 'react-imask';
import { useEffect } from 'react';
import { DatePicker } from '@mui/lab';

interface PhoneCustomProps {
  onChange: (event: { target: { phone: string; value: string } }) => void;
  phone: string;
}

interface CpfCustomProps {
  onChange: (event: { target: { cpf: string; value: string } }) => void;
  cpf: string;
}

interface CepCustomProps {
  onChange: (event: { target: { cep: string; value: string } }) => void;
  cep: string;
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

const CpfMaskCustom = React.forwardRef<HTMLElement, CpfCustomProps>(
  (props, ref) => {
    const { onChange, ...other } = props;
    return (
      <IMaskInput
        {...other}
        mask="000.000.000-00"
        onAccept={(value: any) =>
          onChange({ target: { cpf: props.cpf, value } })
        }
        unmask={true}
      />
    );
  }
);

const CepMaskCustom = React.forwardRef<HTMLElement, CepCustomProps>(
  (props, ref) => {
    const { onChange, ...other } = props;
    return (
      <IMaskInput
        {...other}
        mask="00000-000"
        onAccept={(value: any) =>
          onChange({ target: { cep: props.cep, value } })
        }
        unmask={true}
      />
    );
  }
);

export default function Guarantor({ register, errors, watch, setValue }) {
  useEffect(() => {
    register('guarantorName');
    register('guarantorAddress');
    register('guarantorResidentialTime');
    register('guarantorDistrict');
    register('guarantorCep');
    register('guarantorCity');
    register('guarantorEmail');
    register('guarantorResidentialPhone');
    register('guarantorNationality');
    register('guarantorNaturalFrom');
    register('guarantorDateOfBirth');
    register('guarantorCivilStatus');
    register('guarantorCpf');
    register('guarantorRg');
    register('guarantorProfession');
    register('guarantorFatherName');
    register('guarantorMotherName');

    register('guarantorSpouseName');
    register('guarantorSpouseNationality');
    register('guarantorSpouseProfession');
    register('guarantorSpouseRg');
    register('guarantorSpouseCpf');
    register('guarantorSpouseNumberOfSons');

    register('guarantorName_2');
    register('guarantorAddress_2');
    register('guarantorResidentialTime_2');
    register('guarantorDistrict_2');
    register('guarantorCep_2');
    register('guarantorCity_2');
    register('guarantorEmail_2');
    register('guarantorResidentialPhone_2');
    register('guarantorNationality_2');
    register('guarantorNaturalFrom_2');
    register('guarantorDateOfBirth_2');
    register('guarantorCivilStatus_2');
    register('guarantorCpf_2');
    register('guarantorRg_2');
    register('guarantorProfession_2');
    register('guarantorFatherName_2');
    register('guarantorMotherName_2');

    register('guarantorSpouseName_2');
    register('guarantorSpouseNationality_2');
    register('guarantorSpouseProfession_2');
    register('guarantorSpouseRg_2');
    register('guarantorSpouseCpf_2');
    register('guarantorSpouseNumberOfSons_2');
  }, [register]);

  return (
    <>
      <Grid item xs={12}>
        <Card>
          <CardHeader title="1° Fiador " />

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
                  error={!!errors?.guarantorName}
                  helperText={errors?.guarantorName?.message || ''}
                  label="Nome"
                  required
                  onChange={(event) =>
                    setValue('guarantorName', event.target.value)
                  }
                />
              </Grid>

              <Grid item md={8} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorAddress}
                  helperText={errors?.guarantorAddress?.message || ''}
                  label="Endereço"
                  required
                  onChange={(event) =>
                    setValue('guarantorAddress', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorResidentialTime}
                  helperText={errors?.guarantorResidentialTime?.message || ''}
                  label="Tempo de residência"
                  required
                  onChange={(event) =>
                    setValue('guarantorResidentialTime', event.target.value)
                  }
                />
              </Grid>

              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorDistrict}
                  helperText={errors?.guarantorDistrict?.message || ''}
                  label="Bairro"
                  required
                  onChange={(event) =>
                    setValue('guarantorDistrict', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorCep}
                  helperText={errors?.guarantorCep?.message || ''}
                  label="CEP"
                  required
                  value={watch('guarantorCep') || ''}
                  onChange={(event) =>
                    setValue('guarantorCep', event.target.value)
                  }
                  InputProps={{
                    inputComponent: CepMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorCity}
                  helperText={errors?.guarantorCity?.message || ''}
                  label="Cidade"
                  required
                  onChange={(event) =>
                    setValue('guarantorCity', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorResidentialPhone}
                  helperText={errors?.guarantorResidentialPhone?.message || ''}
                  label="Telefone (Residencial)"
                  value={watch('guarantorResidentialPhone') || ''}
                  required
                  onChange={(event) =>
                    setValue('guarantorResidentialPhone', event.target.value)
                  }
                  InputProps={{
                    inputComponent: PhoneMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>

              <Grid item md={9} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorEmail}
                  helperText={errors?.guarantorEmail?.message || ''}
                  label="Email"
                  required
                  onChange={(event) =>
                    setValue('guarantorEmail', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorCellPhone}
                  helperText={errors?.guarantorCellPhone?.message || ''}
                  label="Telefone (Celular)"
                  value={watch('guarantorCellPhone') || ''}
                  required
                  onChange={(event) =>
                    setValue('guarantorCellPhone', event.target.value)
                  }
                  InputProps={{
                    inputComponent: PhoneMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>

              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorNationality}
                  helperText={errors?.guarantorNationality?.message || ''}
                  label="Nacionalidade"
                  required
                  onChange={(event) =>
                    setValue('guarantorNationality', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorNaturalFrom}
                  helperText={errors?.guarantorNaturalFrom?.message || ''}
                  label="Natural de"
                  required
                  onChange={(event) =>
                    setValue('guarantorNaturalFrom', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <DatePicker
                  label="Data de Nascimento"
                  value={watch().guarantorDateOfBirth || null}
                  onChange={(date) => {
                    setValue('guarantorDateOfBirth', date);
                  }}
                  renderInput={(params) => (
                    <TextField
                      fullWidth
                      required
                      {...params}
                      error={!!errors?.guarantorDateOfBirth}
                      helperText={errors?.guarantorDateOfBirth?.message || ''}
                    />
                  )}
                  inputFormat="dd/MM/yyyy"
                  maxDate={new Date()}
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <FormControl fullWidth required>
                  <InputLabel id="guarantorCivilStatusLabel">
                    Estado civil
                  </InputLabel>
                  <Select
                    labelId="guarantorCivilStatusLabel"
                    id="guarantorCivilStatus"
                    label="Estado civil"
                    defaultValue=""
                    error={!!errors?.guarantorCivilStatus}
                    value={watch().guarantorCivilStatus || ''}
                    onChange={(event) =>
                      setValue('guarantorCivilStatus', event.target.value)
                    }
                  >
                    <MenuItem value={'solteiro(a)'}>Solteiro(a)</MenuItem>
                    <MenuItem value={'casado(a)'}>Casado(a)</MenuItem>
                    <MenuItem value={'viuvo(a)'}>Viúvo(a)</MenuItem>
                  </Select>
                </FormControl>
              </Grid>

              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorRg}
                  helperText={errors?.guarantorRg?.message || ''}
                  label="RG"
                  required
                  onChange={(event) =>
                    setValue('guarantorRg', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorCpf}
                  helperText={errors?.guarantorCpf?.message || ''}
                  value={watch('guarantorCpf') || ''}
                  label="CPF"
                  required
                  onChange={(event) =>
                    setValue('guarantorCpf', event.target.value)
                  }
                  InputProps={{
                    inputComponent: CpfMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorProfession}
                  helperText={errors?.guarantorProfession?.message || ''}
                  label="Profissão"
                  required
                  onChange={(event) =>
                    setValue('guarantorProfession', event.target.value)
                  }
                />
              </Grid>

              <Grid item md={6} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorFatherName}
                  helperText={errors?.guarantorFatherName?.message || ''}
                  label="Nome do pai"
                  onChange={(event) =>
                    setValue('guarantorFatherName', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={6} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorMotherName}
                  helperText={errors?.guarantorMotherName?.message || ''}
                  label="Nome da mãe"
                  required
                  onChange={(event) =>
                    setValue('guarantorMotherName', event.target.value)
                  }
                />
              </Grid>
            </Grid>
          </CardContent>
        </Card>
      </Grid>

      {watch('guarantorCivilStatus') === 'casado(a)' && (
        <Grid item xs={12}>
          <Card>
            <CardHeader title="Cônjuge" />
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
                    error={!!errors?.guarantorSpouseName}
                    helperText={errors?.guarantorSpouseName?.message || ''}
                    label="Nome"
                    required
                    onChange={(event) =>
                      setValue('guarantorSpouseName', event.target.value)
                    }
                  />
                </Grid>
                <Grid item md={4} xs={12}>
                  <TextField
                    fullWidth
                    error={!!errors?.guarantorSpouseNationality}
                    helperText={
                      errors?.guarantorSpouseNationality?.message || ''
                    }
                    label="Nacionalidade"
                    required
                    onChange={(event) =>
                      setValue('guarantorSpouseNationality', event.target.value)
                    }
                  />
                </Grid>

                <Grid item md={3} xs={12}>
                  <TextField
                    fullWidth
                    error={!!errors?.guarantorSpouseProfession}
                    helperText={
                      errors?.guarantorSpouseProfession?.message || ''
                    }
                    label="Profissão"
                    required
                    onChange={(event) =>
                      setValue('guarantorSpouseProfession', event.target.value)
                    }
                  />
                </Grid>
                <Grid item md={3} xs={12}>
                  <TextField
                    fullWidth
                    error={!!errors?.guarantorSpouseRg}
                    helperText={errors?.guarantorSpouseRg?.message || ''}
                    label="RG"
                    required
                    onChange={(event) =>
                      setValue('guarantorSpouseRg', event.target.value)
                    }
                  />
                </Grid>
                <Grid item md={3} xs={12}>
                  <TextField
                    fullWidth
                    error={!!errors?.guarantorSpouseCpf}
                    helperText={errors?.guarantorSpouseCpf?.message || ''}
                    label="CPF"
                    value={watch('guarantorSpouseCpf') || ''}
                    required
                    onChange={(event) =>
                      setValue('guarantorSpouseCpf', event.target.value)
                    }
                    InputProps={{
                      inputComponent: CpfMaskCustom as any,
                    }}
                    InputLabelProps={{ shrink: true }}
                  />
                </Grid>
                <Grid item md={3} xs={12}>
                  <TextField
                    fullWidth
                    error={!!errors?.guarantorSpouseNumberOfSons}
                    helperText={
                      errors?.guarantorSpouseNumberOfSons?.message || ''
                    }
                    label="Número de filhos"
                    required
                    onChange={(event) =>
                      setValue(
                        'guarantorSpouseNumberOfSons',
                        event.target.value
                      )
                    }
                  />
                </Grid>
              </Grid>
            </CardContent>
          </Card>
        </Grid>
      )}
      <Grid item xs={12}>
        <Card>
          <CardHeader title="2° Fiador " />
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
                  error={!!errors?.guarantorName_2}
                  helperText={errors?.guarantorName_2?.message || ''}
                  label="Nome"
                  required
                  onChange={(event) =>
                    setValue('guarantorName_2', event.target.value)
                  }
                />
              </Grid>

              <Grid item md={8} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorAddress_2}
                  helperText={errors?.guarantorAddress_2?.message || ''}
                  label="Endereço"
                  required
                  onChange={(event) =>
                    setValue('guarantorAddress_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorResidentialTime_2}
                  helperText={errors?.guarantorResidentialTime_2?.message || ''}
                  label="Tempo de residência"
                  required
                  onChange={(event) =>
                    setValue('guarantorResidentialTime_2', event.target.value)
                  }
                />
              </Grid>

              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorDistrict_2}
                  helperText={errors?.guarantorDistrict_2?.message || ''}
                  label="Bairro"
                  required
                  onChange={(event) =>
                    setValue('guarantorDistrict_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorCep_2}
                  helperText={errors?.guarantorCep_2?.message || ''}
                  label="CEP"
                  value={watch('guarantorCep_2') || ''}
                  required
                  onChange={(event) =>
                    setValue('guarantorCep_2', event.target.value)
                  }
                  InputProps={{
                    inputComponent: CepMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorCity_2}
                  helperText={errors?.guarantorCity_2?.message || ''}
                  label="Cidade"
                  required
                  onChange={(event) =>
                    setValue('guarantorCity_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorResidentialPhone_2}
                  helperText={
                    errors?.guarantorResidentialPhone_2?.message || ''
                  }
                  label="Telefone (Residencial)"
                  required
                  value={watch('guarantorResidentialPhone_2') || ''}
                  onChange={(event) =>
                    setValue('guarantorResidentialPhone_2', event.target.value)
                  }
                  InputProps={{
                    inputComponent: PhoneMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>

              <Grid item md={9} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorEmail_2}
                  helperText={errors?.guarantorEmail_2?.message || ''}
                  label="Email"
                  required
                  onChange={(event) =>
                    setValue('guarantorEmail_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorCellPhone_2}
                  helperText={errors?.guarantorCellPhone_2?.message || ''}
                  label="Telefone (Celular)"
                  value={watch('guarantorCellPhone_2') || ''}
                  required
                  onChange={(event) =>
                    setValue('guarantorCellPhone_2', event.target.value)
                  }
                  InputProps={{
                    inputComponent: PhoneMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>

              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorNationality_2}
                  helperText={errors?.guarantorNationality_2?.message || ''}
                  label="Nacionalidade"
                  required
                  onChange={(event) =>
                    setValue('guarantorNationality_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorNaturalFrom_2}
                  helperText={errors?.guarantorNaturalFrom_2?.message || ''}
                  label="Natural de"
                  required
                  onChange={(event) =>
                    setValue('guarantorNaturalFrom_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <DatePicker
                  label="Data de Nascimento"
                  value={watch().guarantorDateOfBirth_2 || null}
                  onChange={(date) => {
                    setValue('guarantorDateOfBirth_2', date);
                  }}
                  renderInput={(params) => (
                    <TextField
                      fullWidth
                      required
                      {...params}
                      error={!!errors?.guarantorDateOfBirth_2}
                      helperText={errors?.guarantorDateOfBirth_2?.message || ''}
                    />
                  )}
                  inputFormat="dd/MM/yyyy"
                  maxDate={new Date()}
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <FormControl fullWidth required>
                  <InputLabel id="guarantorCivilStatusLabel_2">
                    Estado civil
                  </InputLabel>
                  <Select
                    labelId="guarantorCivilStatusLabel_2"
                    id="guarantorCivilStatus_2"
                    label="Estado civil"
                    defaultValue=""
                    error={!!errors?.guarantorCivilStatus_2}
                    value={watch().guarantorCivilStatus_2 || ''}
                    onChange={(event) =>
                      setValue('guarantorCivilStatus_2', event.target.value)
                    }
                  >
                    <MenuItem value={'solteiro(a)'}>Solteiro(a)</MenuItem>
                    <MenuItem value={'casado(a)'}>Casado(a)</MenuItem>
                    <MenuItem value={'viuvo(a)'}>Viúvo(a)</MenuItem>
                  </Select>
                </FormControl>
              </Grid>

              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorRg_2}
                  helperText={errors?.guarantorRg_2?.message || ''}
                  label="RG"
                  required
                  onChange={(event) =>
                    setValue('guarantorRg_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorCpf_2}
                  helperText={errors?.guarantorCpf_2?.message || ''}
                  label="CPF"
                  value={watch('guarantorCpf_2') || ''}
                  required
                  onChange={(event) =>
                    setValue('guarantorCpf_2', event.target.value)
                  }
                  InputProps={{
                    inputComponent: CpfMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorProfession_2}
                  helperText={errors?.guarantorProfession_2?.message || ''}
                  label="Profissão"
                  required
                  onChange={(event) =>
                    setValue('guarantorProfession_2', event.target.value)
                  }
                />
              </Grid>

              <Grid item md={6} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorFatherName_2}
                  helperText={errors?.guarantorFatherName_2?.message || ''}
                  label="Nome do pai"
                  onChange={(event) =>
                    setValue('guarantorFatherName_2', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={6} xs={12}>
                <TextField
                  fullWidth
                  error={!!errors?.guarantorMotherName_2}
                  helperText={errors?.guarantorMotherName_2?.message || ''}
                  label="Nome da mãe"
                  required
                  onChange={(event) =>
                    setValue('guarantorMotherName_2', event.target.value)
                  }
                />
              </Grid>
            </Grid>
          </CardContent>
        </Card>
      </Grid>

      {watch('guarantorCivilStatus_2') === 'casado(a)' && (
        <Grid item xs={12}>
          <Card>
            <CardHeader title="Cônjuge" />
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
                    error={!!errors?.guarantorSpouseName_2}
                    helperText={errors?.guarantorSpouseName_2?.message || ''}
                    label="Nome"
                    required
                    onChange={(event) =>
                      setValue('guarantorSpouseName_2', event.target.value)
                    }
                  />
                </Grid>
                <Grid item md={4} xs={12}>
                  <TextField
                    fullWidth
                    error={!!errors?.guarantorSpouseNationality_2}
                    helperText={
                      errors?.guarantorSpouseNationality_2?.message || ''
                    }
                    label="Nacionalidade"
                    required
                    onChange={(event) =>
                      setValue(
                        'guarantorSpouseNationality_2',
                        event.target.value
                      )
                    }
                  />
                </Grid>

                <Grid item md={3} xs={12}>
                  <TextField
                    fullWidth
                    error={!!errors?.guarantorSpouseProfession_2}
                    helperText={
                      errors?.guarantorSpouseProfession_2?.message || ''
                    }
                    label="Profissão"
                    required
                    onChange={(event) =>
                      setValue(
                        'guarantorSpouseProfession_2',
                        event.target.value
                      )
                    }
                  />
                </Grid>
                <Grid item md={3} xs={12}>
                  <TextField
                    fullWidth
                    error={!!errors?.guarantorSpouseRg_2}
                    helperText={errors?.guarantorSpouseRg_2?.message || ''}
                    label="RG"
                    required
                    onChange={(event) =>
                      setValue('guarantorSpouseRg_2', event.target.value)
                    }
                  />
                </Grid>
                <Grid item md={3} xs={12}>
                  <TextField
                    fullWidth
                    error={!!errors?.guarantorSpouseCpf_2}
                    helperText={errors?.guarantorSpouseCpf_2?.message || ''}
                    value={watch('guarantorSpouseCpf_2') || ''}
                    label="CPF"
                    required
                    onChange={(event) =>
                      setValue('guarantorSpouseCpf_2', event.target.value)
                    }
                    InputProps={{
                      inputComponent: CpfMaskCustom as any,
                    }}
                    InputLabelProps={{ shrink: true }}
                  />
                </Grid>
                <Grid item md={3} xs={12}>
                  <TextField
                    fullWidth
                    error={!!errors?.guarantorSpouseNumberOfSons_2}
                    helperText={
                      errors?.guarantorSpouseNumberOfSons_2?.message || ''
                    }
                    label="Número de filhos"
                    required
                    onChange={(event) =>
                      setValue(
                        'guarantorSpouseNumberOfSons_2',
                        event.target.value
                      )
                    }
                  />
                </Grid>
              </Grid>
            </CardContent>
          </Card>
        </Grid>
      )}
    </>
  );
}
