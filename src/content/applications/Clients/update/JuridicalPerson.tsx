import { DatePicker } from '@mui/lab';
import {
  Grid,
  TextField,
  Card,
  CardHeader,
  CardContent,
  Divider,
  FormControl,
  InputLabel,
  Select,
  MenuItem,
} from '@mui/material';
import * as React from 'react';
import { IMaskInput } from 'react-imask';

import { useEffect } from 'react';

interface PhoneCustomProps {
  onChange: (event: { target: { phone: string; value: string } }) => void;
  phone: string;
}

interface CpfCustomProps {
  onChange: (event: { target: { cpf: string; value: string } }) => void;
  cpf: string;
}

interface CnpjCustomProps {
  onChange: (event: { target: { cnpj: string; value: string } }) => void;
  cnpj: string;
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
const CnpjMaskCustom = React.forwardRef<HTMLElement, CnpjCustomProps>(
  (props, ref) => {
    const { onChange, ...other } = props;
    return (
      <IMaskInput
        {...other}
        mask="00.000.000/0000-00"
        onAccept={(value: any) =>
          onChange({ target: { cnpj: props.cnpj, value } })
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

function JuridicalPerson({ register, errors, watch, setValue, client }) {
  useEffect(() => {
    register('companyName_juridicalPerson_locatario');
    register('companyRepresentative_juridicalPerson_locatario');
    register('profession_juridicalPerson_locatario');
    register('address_juridicalPerson_locatario');
    register('residenceTime_juridicalPerson_locatario');
    register('district_juridicalPerson_locatario');
    register('cep_juridicalPerson_locatario');
    register('city_juridicalPerson_locatario');
    register('civilStatus_juridicalPerson_locatario');
    register('cpf_juridicalPerson_locatario');
    register('rg_juridicalPerson_locatario');
    register('dateOfBirth_juridicalPerson_locatario');
    register('phoneNumber_juridicalPerson_locatario');
    register('cnpj_juridicalPerson_locatario');
    register('stateRegistration_juridicalPerson_locatario');
    register('phoneNumberCommercial_juridicalPerson_locatario');
    register('branchOfActivityCompany_juridicalPerson_locatario');
    register('timeOfActivityCompany_juridicalPerson_locatario');
    register('previousAddress_juridicalPerson_locatario');
    register('phoneResidential_juridicalPerson_locatario');
    register('companyDistrict_juridicalPerson_locatario');
    register('companyCep_juridicalPerson_locatario');
    register('companyCity_juridicalPerson_locatario');
  }, [register]);

  useEffect(() => {
    setValue(
      'companyName_juridicalPerson_locatario',
      client.companyName_juridicalPerson_locatario
    );
    setValue(
      'companyRepresentative_juridicalPerson_locatario',
      client.companyRepresentative_juridicalPerson_locatario
    );
    setValue(
      'profession_juridicalPerson_locatario',
      client.profession_juridicalPerson_locatario
    );
    setValue(
      'address_juridicalPerson_locatario',
      client.address_juridicalPerson_locatario
    );
    setValue(
      'residenceTime_juridicalPerson_locatario',
      client.residenceTime_juridicalPerson_locatario
    );
    setValue(
      'district_juridicalPerson_locatario',
      client.district_juridicalPerson_locatario
    );
    setValue(
      'cep_juridicalPerson_locatario',
      client.cep_juridicalPerson_locatario
    );
    setValue(
      'city_juridicalPerson_locatario',
      client.city_juridicalPerson_locatario
    );
    setValue(
      'civilStatus_juridicalPerson_locatario',
      client.civilStatus_juridicalPerson_locatario
    );
    setValue(
      'cpf_juridicalPerson_locatario',
      client.cpf_juridicalPerson_locatario
    );
    setValue(
      'rg_juridicalPerson_locatario',
      client.rg_juridicalPerson_locatario
    );
    setValue(
      'dateOfBirth_juridicalPerson_locatario',
      client.dateOfBirth_juridicalPerson_locatario
    );
    setValue(
      'phoneNumber_juridicalPerson_locatario',
      client.phoneNumber_juridicalPerson_locatario
    );
    setValue(
      'cnpj_juridicalPerson_locatario',
      client.cnpj_juridicalPerson_locatario
    );
    setValue(
      'stateRegistration_juridicalPerson_locatario',
      client.stateRegistration_juridicalPerson_locatario
    );
    setValue(
      'phoneNumberCommercial_juridicalPerson_locatario',
      client.phoneNumberCommercial_juridicalPerson_locatario
    );
    setValue(
      'branchOfActivityCompany_juridicalPerson_locatario',
      client.branchOfActivityCompany_juridicalPerson_locatario
    );
    setValue(
      'timeOfActivityCompany_juridicalPerson_locatario',
      client.timeOfActivityCompany_juridicalPerson_locatario
    );
    setValue(
      'previousAddress_juridicalPerson_locatario',
      client.previousAddress_juridicalPerson_locatario
    );
    setValue(
      'phoneResidential_juridicalPerson_locatario',
      client.phoneResidential_juridicalPerson_locatario
    );
    setValue(
      'companyDistrict_juridicalPerson_locatario',
      client.companyDistrict_juridicalPerson_locatario
    );
    setValue(
      'companyCep_juridicalPerson_locatario',
      client.companyCep_juridicalPerson_locatario
    );
    setValue(
      'companyCity_juridicalPerson_locatario',
      client.companyName_juridicalPerson_locatario
    );
  }, [setValue, client]);

  return (
    <>
      <Grid item xs={12}>
        <Card>
          <CardHeader title="Locatário" />
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
                  value={watch().companyName_juridicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.companyName_juridicalPerson_locatario}
                  helperText={
                    errors?.companyName_juridicalPerson_locatario?.message || ''
                  }
                  label="Empresa"
                  required
                  onChange={(event) =>
                    setValue(
                      'companyName_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>

              <Grid item md={8} xs={12}>
                <TextField
                  value={
                    watch().companyRepresentative_juridicalPerson_locatario ||
                    ''
                  }
                  fullWidth
                  error={
                    !!errors?.companyRepresentative_juridicalPerson_locatario
                  }
                  helperText={
                    errors?.companyRepresentative_juridicalPerson_locatario
                      ?.message || ''
                  }
                  label="Representante"
                  required
                  onChange={(event) =>
                    setValue(
                      'companyRepresentative_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().profession_juridicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.profession_juridicalPerson_locatario}
                  helperText={
                    errors?.profession_juridicalPerson_locatario?.message || ''
                  }
                  label="Profissão"
                  required
                  onChange={(event) =>
                    setValue(
                      'profession_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={8} xs={12}>
                <TextField
                  value={watch().address_juridicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.address_juridicalPerson_locatario}
                  helperText={
                    errors?.address_juridicalPerson_locatario?.message || ''
                  }
                  label="Endereço"
                  required
                  onChange={(event) =>
                    setValue(
                      'address_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().residenceTime_juridicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.residenceTime_juridicalPerson_locatario}
                  helperText={
                    errors?.residenceTime_juridicalPerson_locatario?.message ||
                    ''
                  }
                  label="Tempo de residência"
                  required
                  onChange={(event) =>
                    setValue(
                      'residenceTime_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>

              <Grid item md={3} xs={12}>
                <TextField
                  value={watch().district_juridicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.district_juridicalPerson_locatario}
                  helperText={
                    errors?.district_juridicalPerson_locatario?.message || ''
                  }
                  label="Bairro"
                  required
                  onChange={(event) =>
                    setValue(
                      'district_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  value={watch().cep_juridicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.cep_juridicalPerson_locatario}
                  helperText={
                    errors?.cep_juridicalPerson_locatario?.message || ''
                  }
                  label="CEP"
                  required
                  onChange={(event) =>
                    setValue(
                      'cep_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                  InputProps={{
                    inputComponent: CepMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  value={watch().city_juridicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.city_juridicalPerson_locatario}
                  helperText={
                    errors?.city_juridicalPerson_locatario?.message || ''
                  }
                  label="Cidade"
                  required
                  onChange={(event) =>
                    setValue(
                      'city_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <FormControl fullWidth>
                  <InputLabel id="civilStatus_juridicalPersonLabel_locatario">
                    Estado civil
                  </InputLabel>
                  <Select
                    value={watch().civilStatus_juridicalPerson_locatario || ''}
                    required
                    labelId="civilStatus_juridicalPersonLabel_locatario"
                    id="civilStatus_juridicalPerson_locatario"
                    label="Estado civil"
                    error={!!errors?.civilStatus_juridicalPerson_locatario}
                    onChange={(event) =>
                      setValue(
                        'civilStatus_juridicalPerson_locatario',
                        event.target.value
                      )
                    }
                  >
                    <MenuItem value={'solteiro(a)'}>Solteiro(a)</MenuItem>
                    <MenuItem value={'casado(a)'}>Casado(a)</MenuItem>
                    <MenuItem value={'viuvo(a)'}>Viúvo(a)</MenuItem>
                  </Select>
                </FormControl>
              </Grid>

              <Grid item md={3} xs={12}>
                <TextField
                  value={watch().cpf_juridicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.cpf_juridicalPerson_locatario}
                  label="CPF"
                  required
                  helperText={
                    errors?.cpf_juridicalPerson_locatario?.message || ''
                  }
                  onChange={(event) =>
                    setValue(
                      'cpf_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                  InputProps={{
                    inputComponent: CpfMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  value={watch().rg_juridicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.rg_juridicalPerson_locatario}
                  helperText={
                    errors?.rg_juridicalPerson_locatario?.message || ''
                  }
                  label="RG"
                  required
                  onChange={(event) =>
                    setValue('rg_juridicalPerson_locatario', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <DatePicker
                  label="Data de Nascimento"
                  value={watch().dateOfBirth_juridicalPerson_locatario || null}
                  onChange={(date) => {
                    setValue('dateOfBirth_juridicalPerson_locatario', date);
                  }}
                  renderInput={(params) => (
                    <TextField
                      fullWidth
                      required
                      {...params}
                      error={!!errors?.dateOfBirth_juridicalPerson_locatario}
                      helperText={
                        errors?.dateOfBirth_juridicalPerson_locatario
                          ?.message || ''
                      }
                    />
                  )}
                  inputFormat="dd/MM/yyyy"
                  maxDate={new Date()}
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  value={watch().phoneNumber_juridicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.phoneNumber_juridicalPerson_locatario}
                  label="Telefone (Celular)"
                  required
                  helperText={
                    errors?.phoneNumber_juridicalPerson_locatario?.message || ''
                  }
                  onChange={(event) =>
                    setValue(
                      'phoneNumber_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                  InputProps={{
                    inputComponent: PhoneMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>

              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().cnpj_juridicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.cnpj_juridicalPerson_locatario}
                  label="CNPJ"
                  helperText={
                    errors?.cnpj_juridicalPerson_locatario?.message || ''
                  }
                  required
                  onChange={(event) =>
                    setValue(
                      'cnpj_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                  InputProps={{
                    inputComponent: CnpjMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  value={
                    watch().stateRegistration_juridicalPerson_locatario || ''
                  }
                  fullWidth
                  error={!!errors?.stateRegistration_juridicalPerson_locatario}
                  helperText={
                    errors?.stateRegistration_juridicalPerson_locatario
                      ?.message || ''
                  }
                  label="INSC. Estadual"
                  required
                  onChange={(event) =>
                    setValue(
                      'stateRegistration_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  value={
                    watch().phoneNumberCommercial_juridicalPerson_locatario ||
                    ''
                  }
                  fullWidth
                  error={
                    !!errors?.phoneNumberCommercial_juridicalPerson_locatario
                  }
                  helperText={
                    errors?.phoneNumberCommercial_juridicalPerson_locatario
                      ?.message || ''
                  }
                  label="Telefone comercial"
                  required
                  onChange={(event) =>
                    setValue(
                      'phoneNumberCommercial_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                  InputProps={{
                    inputComponent: PhoneMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>

              <Grid item md={8} xs={12}>
                <TextField
                  value={
                    watch().branchOfActivityCompany_juridicalPerson_locatario ||
                    ''
                  }
                  fullWidth
                  error={
                    !!errors?.branchOfActivityCompany_juridicalPerson_locatario
                  }
                  helperText={
                    errors?.branchOfActivityCompany_juridicalPerson_locatario
                      ?.message || ''
                  }
                  label="Ramo de atividade da empresa"
                  required
                  onChange={(event) =>
                    setValue(
                      'branchOfActivityCompany_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  value={
                    watch().timeOfActivityCompany_juridicalPerson_locatario ||
                    ''
                  }
                  fullWidth
                  error={
                    !!errors?.timeOfActivityCompany_juridicalPerson_locatario
                  }
                  helperText={
                    errors?.timeOfActivityCompany_juridicalPerson_locatario
                      ?.message || ''
                  }
                  label="Tempo de atividade da empresa"
                  required
                  onChange={(event) =>
                    setValue(
                      'timeOfActivityCompany_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>

              <Grid item md={8} xs={12}>
                <TextField
                  value={
                    watch().previousAddress_juridicalPerson_locatario || ''
                  }
                  fullWidth
                  error={!!errors?.previousAddress_juridicalPerson_locatario}
                  helperText={
                    errors?.previousAddress_juridicalPerson_locatario
                      ?.message || ''
                  }
                  label="Endereço anterior da empresa"
                  required
                  onChange={(event) =>
                    setValue(
                      'previousAddress_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  value={
                    watch().phoneResidential_juridicalPerson_locatario || ''
                  }
                  fullWidth
                  error={!!errors?.phoneResidential_juridicalPerson_locatario}
                  helperText={
                    errors?.phoneResidential_juridicalPerson_locatario
                      ?.message || ''
                  }
                  label="Telefone residencial"
                  required
                  onChange={(event) =>
                    setValue(
                      'phoneResidential_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                  InputProps={{
                    inputComponent: PhoneMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>

              <Grid item md={4} xs={12}>
                <TextField
                  value={
                    watch().companyDistrict_juridicalPerson_locatario || ''
                  }
                  fullWidth
                  error={!!errors?.companyDistrict_juridicalPerson_locatario}
                  helperText={
                    errors?.companyDistrict_juridicalPerson_locatario
                      ?.message || ''
                  }
                  label="Bairro"
                  required
                  onChange={(event) =>
                    setValue(
                      'companyDistrict_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().companyCep_juridicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.companyCep_juridicalPerson_locatario}
                  helperText={
                    errors?.companyCep_juridicalPerson_locatario?.message || ''
                  }
                  label="CEP"
                  required
                  onChange={(event) =>
                    setValue(
                      'companyCep_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                  InputProps={{
                    inputComponent: CepMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().companyCity_juridicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.companyCity_juridicalPerson_locatario}
                  helperText={
                    errors?.companyCity_juridicalPerson_locatario?.message || ''
                  }
                  label="Cidade"
                  required
                  onChange={(event) =>
                    setValue(
                      'companyCity_juridicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
            </Grid>
          </CardContent>
        </Card>
      </Grid>
    </>
  );
}

export default JuridicalPerson;
