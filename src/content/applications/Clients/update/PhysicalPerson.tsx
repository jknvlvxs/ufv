import { DatePicker } from '@mui/lab';
import {
  Grid,
  TextField,
  Card,
  CardHeader,
  CardContent,
  Divider,
  FormControl,
  FormLabel,
  RadioGroup,
  FormControlLabel,
  Radio,
  MenuItem,
  InputLabel,
  Select,
  InputAdornment,
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

interface CepCustomProps {
  onChange: (event: { target: { cep: string; value: string } }) => void;
  cep: string;
}

interface MoneyCustomProps {
  onChange: (event: { target: { money: string; value: string } }) => void;
  money: string;
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

function PhysicalPerson({ register, errors, watch, setValue, client }) {
  useEffect(() => {
    register('name_physicalPerson_locatario');
    register('fatherName_physicalPerson_locatario');
    register('motherName_physicalPerson_locatario');
    register('address_physicalPerson_locatario');
    register('residenceTime_physicalPerson_locatario');
    register('district_physicalPerson_locatario');
    register('cep_physicalPerson_locatario');
    register('city_physicalPerson_locatario');
    register('homePhone_physicalPerson_locatario');
    register('email_physicalPerson_locatario');
    register('phoneNumber_physicalPerson_locatario');
    register('nationality_physicalPerson_locatario');
    register('naturalFrom_physicalPerson_locatario');
    register('dateOfBirth_physicalPerson_locatario');
    register('civilStatus_physicalPerson_locatario');
    register('rg_physicalPerson_locatario');
    register('cpf_physicalPerson_locatario');
    register('profession_physicalPerson_locatario');
    register('nameOfPayRent_physicalPerson_locatario');
    register('rentValue_physicalPerson_locatario');
    register('addressOfPayRent_physicalPerson_locatario');
    register('phoneNumberOfPayRent_physicalPerson_locatario');

    register('liveOwnHouse_physicalPerson_locatario');
    register('payRent_physicalPerson_locatario');

    register('company_physicalPerson');
    register('admissionDateCompany_physicalPerson');
    register('addressOfCompany_physicalPerson');
    register('phoneNumberOfCompany_physicalPerson');
    register('districtOfCompany_physicalPerson');
    register('cityOfCompany_physicalPerson');
    register('positionInCompany_physicalPerson');
    register('salary_physicalPerson');
    register('others_physicalPerson');
    register('spouseName_physicalPerson');
    register('spouseNationality_physicalPerson');
    register('spouseProfession_physicalPerson');
    register('spouseRg_physicalPerson');
    register('spouseCpf_physicalPerson');
    register('spouseNumberOfSons_physicalPerson');
  }, [register]);

  useEffect(() => {
    setValue(
      'name_physicalPerson_locatario',
      client.name_physicalPerson_locatario
    );
    setValue(
      'fatherName_physicalPerson_locatario',
      client.fatherName_physicalPerson_locatario
    );
    setValue(
      'motherName_physicalPerson_locatario',
      client.motherName_physicalPerson_locatario
    );
    setValue(
      'address_physicalPerson_locatario',
      client.address_physicalPerson_locatario
    );
    setValue(
      'residenceTime_physicalPerson_locatario',
      client.residenceTime_physicalPerson_locatario
    );
    setValue(
      'district_physicalPerson_locatario',
      client.district_physicalPerson_locatario
    );
    setValue(
      'cep_physicalPerson_locatario',
      client.cep_physicalPerson_locatario
    );
    setValue(
      'city_physicalPerson_locatario',
      client.city_physicalPerson_locatario
    );
    setValue(
      'homePhone_physicalPerson_locatario',
      client.homePhone_physicalPerson_locatario
    );
    setValue(
      'email_physicalPerson_locatario',
      client.email_physicalPerson_locatario
    );
    setValue(
      'phoneNumber_physicalPerson_locatario',
      client.phoneNumber_physicalPerson_locatario
    );
    setValue(
      'nationality_physicalPerson_locatario',
      client.nationality_physicalPerson_locatario
    );
    setValue(
      'naturalFrom_physicalPerson_locatario',
      client.naturalFrom_physicalPerson_locatario
    );
    setValue(
      'dateOfBirth_physicalPerson_locatario',
      client.dateOfBirth_physicalPerson_locatario
    );
    setValue(
      'civilStatus_physicalPerson_locatario',
      client.civilStatus_physicalPerson_locatario
    );
    setValue(
      'cpf_physicalPerson_locatario',
      client.cpf_physicalPerson_locatario
    );
    setValue('rg_physicalPerson_locatario', client.rg_physicalPerson_locatario);
    setValue(
      'profession_physicalPerson_locatario',
      client.profession_physicalPerson_locatario
    );
    setValue(
      'liveOwnHouse_physicalPerson_locatario',
      client.liveOwnHouse_physicalPerson_locatario
    );
    setValue(
      'payRent_physicalPerson_locatario',
      client.payRent_physicalPerson_locatario
    );
    setValue(
      'nameOfPayRent_physicalPerson_locatario',
      client.nameOfPayRent_physicalPerson_locatario
    );
    setValue(
      'rentValue_physicalPerson_locatario',
      client.rentValue_physicalPerson_locatario
    );
    setValue(
      'addressOfPayRent_physicalPerson_locatario',
      client.addressOfPayRent_physicalPerson_locatario
    );
    setValue(
      'phoneNumberOfPayRent_physicalPerson_locatario',
      client.phoneNumberOfPayRent_physicalPerson_locatario
    );
    setValue(
      'liveOwnHouse_physicalPerson_locatario',
      client.liveOwnHouse_physicalPerson_locatario
    );
    setValue(
      'payRent_physicalPerson_locatario',
      client.payRent_physicalPerson_locatario
    );
    setValue('company_physicalPerson', client.company_physicalPerson);
    setValue(
      'admissionDateCompany_physicalPerson',
      client.admissionDateCompany_physicalPerson
    );
    setValue(
      'addressOfCompany_physicalPerson',
      client.addressOfCompany_physicalPerson
    );
    setValue(
      'phoneNumberOfCompany_physicalPerson',
      client.phoneNumberOfCompany_physicalPerson
    );
    setValue(
      'districtOfCompany_physicalPerson',
      client.districtOfCompany_physicalPerson
    );
    setValue(
      'cityOfCompany_physicalPerson',
      client.cityOfCompany_physicalPerson
    );
    setValue(
      'positionInCompany_physicalPerson',
      client.positionInCompany_physicalPerson
    );
    setValue('salary_physicalPerson', client.salary_physicalPerson);
    setValue('others_physicalPerson', client.others_physicalPerson);

    setValue('spouseName_physicalPerson', client.spouseName_physicalPerson);
    setValue(
      'spouseNationality_physicalPerson',
      client.spouseNationality_physicalPerson
    );
    setValue(
      'spouseProfession_physicalPerson',
      client.spouseProfession_physicalPerson
    );
    setValue('spouseRg_physicalPerson', client.spouseRg_physicalPerson);
    setValue('spouseCpf_physicalPerson', client.spouseCpf_physicalPerson);
    setValue(
      'spouseNumberOfSons_physicalPerson',
      client.spouseNumberOfSons_physicalPerson
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
                  value={watch().name_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.name_physicalPerson_locatario}
                  helperText={
                    errors?.name_physicalPerson_locatario?.message || ''
                  }
                  label="Nome completo"
                  required
                  onChange={(event) => {
                    setValue(
                      'name_physicalPerson_locatario',
                      event.target.value
                    );
                  }}
                />
              </Grid>

              <Grid item md={6} xs={12}>
                <TextField
                  value={watch().fatherName_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.fatherName_physicalPerson_locatario}
                  helperText={
                    errors?.fatherName_physicalPerson_locatario?.message || ''
                  }
                  label="Nome do pai"
                  onChange={(event) => {
                    setValue(
                      'fatherName_physicalPerson_locatario',
                      event.target.value
                    );
                  }}
                />
              </Grid>
              <Grid item md={6} xs={12}>
                <TextField
                  value={watch().motherName_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.motherName_physicalPerson_locatario}
                  helperText={
                    errors?.motherName_physicalPerson_locatario?.message || ''
                  }
                  label="Nome da mãe"
                  required
                  onChange={(event) =>
                    setValue(
                      'motherName_physicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>

              <Grid item md={10} xs={12}>
                <TextField
                  value={watch().address_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.address_physicalPerson_locatario}
                  helperText={
                    errors?.address_physicalPerson_locatario?.message || ''
                  }
                  label="Endereço"
                  required
                  onChange={(event) =>
                    setValue(
                      'address_physicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={2} xs={12}>
                <TextField
                  value={watch().residenceTime_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.residenceTime_physicalPerson_locatario}
                  helperText={
                    errors?.residenceTime_physicalPerson_locatario?.message ||
                    ''
                  }
                  label="Tempo de residência"
                  required
                  onChange={(event) =>
                    setValue(
                      'residenceTime_physicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>

              <Grid item md={3} xs={12}>
                <TextField
                  value={watch().district_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.district_physicalPerson_locatario}
                  helperText={
                    errors?.district_physicalPerson_locatario?.message || ''
                  }
                  label="Bairro"
                  required
                  onChange={(event) =>
                    setValue(
                      'district_physicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  value={watch().cep_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.cep_physicalPerson_locatario}
                  helperText={
                    errors?.cep_physicalPerson_locatario?.message || ''
                  }
                  label="CEP"
                  required
                  onChange={(event) =>
                    setValue('cep_physicalPerson_locatario', event.target.value)
                  }
                  InputProps={{
                    inputComponent: CepMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  value={watch().city_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.city_physicalPerson_locatario}
                  helperText={
                    errors?.city_physicalPerson_locatario?.message || ''
                  }
                  label="Cidade"
                  required
                  onChange={(event) =>
                    setValue(
                      'city_physicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  value={watch().homePhone_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.homePhone_physicalPerson_locatario}
                  helperText={
                    errors?.homePhone_physicalPerson_locatario?.message || ''
                  }
                  label="Telefone residencial"
                  required
                  onChange={(event) =>
                    setValue(
                      'homePhone_physicalPerson_locatario',
                      event.target.value
                    )
                  }
                  InputProps={{
                    inputComponent: PhoneMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>

              <Grid item md={9} xs={12}>
                <TextField
                  value={watch().email_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.email_physicalPerson_locatario}
                  helperText={
                    errors?.email_physicalPerson_locatario?.message || ''
                  }
                  label="Email"
                  required
                  onChange={(event) =>
                    setValue(
                      'email_physicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  value={watch().phoneNumber_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.phoneNumber_physicalPerson_locatario}
                  helperText={
                    errors?.phoneNumber_physicalPerson_locatario?.message || ''
                  }
                  label="Celular"
                  required
                  onChange={(event) =>
                    setValue(
                      'phoneNumber_physicalPerson_locatario',
                      event.target.value
                    )
                  }
                  InputProps={{
                    inputComponent: PhoneMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>

              <Grid item md={3} xs={12}>
                <TextField
                  value={watch().nationality_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.nationality_physicalPerson_locatario}
                  helperText={
                    errors?.nationality_physicalPerson_locatario?.message || ''
                  }
                  label="Nacionalidade"
                  required
                  onChange={(event) =>
                    setValue(
                      'nationality_physicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <TextField
                  value={watch().naturalFrom_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.naturalFrom_physicalPerson_locatario}
                  helperText={
                    errors?.naturalFrom_physicalPerson_locatario?.message || ''
                  }
                  label="Natural de"
                  required
                  onChange={(event) =>
                    setValue(
                      'naturalFrom_physicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <DatePicker
                  label="Data de Nascimento"
                  value={watch().dateOfBirth_physicalPerson_locatario || null}
                  onChange={(date) => {
                    setValue('dateOfBirth_physicalPerson_locatario', date);
                  }}
                  renderInput={(params) => (
                    <TextField
                      fullWidth
                      helperText={
                        errors?.dateOfBirth_physicalPerson_locatario?.message ||
                        ''
                      }
                      required
                      {...params}
                      error={!!errors?.dateOfBirth_physicalPerson_locatario}
                    />
                  )}
                  inputFormat="dd/MM/yyyy"
                  maxDate={new Date()}
                />
              </Grid>
              <Grid item md={3} xs={12}>
                <FormControl fullWidth>
                  <InputLabel id="civilStatus_physicalPersonLabel_locatario">
                    Estado civil
                  </InputLabel>
                  <Select
                    required
                    labelId="civilStatus_physicalPersonLabel_locatario"
                    id="civilStatus_physicalPerson_locatario"
                    label="Estado civil"
                    error={!!errors?.civilStatus_physicalPerson_locatario}
                    value={watch().civilStatus_physicalPerson_locatario || ''}
                    onChange={(event) =>
                      setValue(
                        'civilStatus_physicalPerson_locatario',
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

              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().rg_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.rg_physicalPerson_locatario}
                  helperText={
                    errors?.rg_physicalPerson_locatario?.message || ''
                  }
                  label="RG"
                  required
                  onChange={(event) =>
                    setValue('rg_physicalPerson_locatario', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().cpf_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.cpf_physicalPerson_locatario}
                  helperText={
                    errors?.cpf_physicalPerson_locatario?.message || ''
                  }
                  label="CPF"
                  required
                  onChange={(event) =>
                    setValue('cpf_physicalPerson_locatario', event.target.value)
                  }
                  InputProps={{
                    inputComponent: CpfMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().profession_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.profession_physicalPerson_locatario}
                  helperText={
                    errors?.profession_physicalPerson_locatario?.message || ''
                  }
                  label="Profissão"
                  required
                  onChange={(event) =>
                    setValue(
                      'profession_physicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>

              <Grid item md={2} ml={2.5} xs={12}>
                <FormControl
                  required
                  error={!!errors?.liveOwnHouse_physicalPerson_locatario}
                >
                  <FormLabel id="liveOwnHouse_physicalPersonLabel_locatario">
                    Reside em casa própria:
                  </FormLabel>
                  <RadioGroup
                    value={watch().liveOwnHouse_physicalPerson_locatario || ''}
                    row
                    aria-labelledby="liveOwnHouse_physicalPersonLabel_locatario"
                    name="position"
                    onChange={(event) =>
                      setValue(
                        'liveOwnHouse_physicalPerson_locatario',
                        event.target.value
                      )
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
              <Grid item md={2} ml={2.5} xs={12}>
                <FormControl
                  required
                  error={!!errors?.payRent_physicalPerson_locatario}
                >
                  <FormLabel id="payRent_physicalPersonLabel_locatario">
                    Paga aluguel:
                  </FormLabel>
                  <RadioGroup
                    value={watch().payRent_physicalPerson_locatario || ''}
                    row
                    aria-labelledby="payRent_physicalPersonLabel_locatario"
                    name="position"
                    onChange={(event) =>
                      setValue(
                        'payRent_physicalPerson_locatario',
                        event.target.value
                      )
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

              <Grid item md={8} xs={12}>
                <TextField
                  value={watch().nameOfPayRent_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.nameOfPayRent_physicalPerson_locatario}
                  helperText={
                    errors?.nameOfPayRent_physicalPerson_locatario?.message ||
                    ''
                  }
                  label="Nome da imobiliária ou proprietário a quem você paga o aluguel"
                  onChange={(event) =>
                    setValue(
                      'nameOfPayRent_physicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>

              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().rentValue_physicalPerson_locatario || ''}
                  fullWidth
                  error={!!errors?.rentValue_physicalPerson_locatario}
                  helperText={
                    errors?.rentValue_physicalPerson_locatario?.message || ''
                  }
                  label="Valor"
                  onChange={(event) =>
                    setValue(
                      'rentValue_physicalPerson_locatario',
                      event.target.value
                    )
                  }
                  InputProps={{
                    inputComponent: MoneyMaskCustom as any,
                    startAdornment: (
                      <InputAdornment position="start">R$</InputAdornment>
                    ),
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>

              <Grid item md={8} xs={12}>
                <TextField
                  fullWidth
                  value={
                    watch().addressOfPayRent_physicalPerson_locatario || ''
                  }
                  error={!!errors?.addressOfPayRent_physicalPerson_locatario}
                  helperText={
                    errors?.addressOfPayRent_physicalPerson_locatario
                      ?.message || ''
                  }
                  label="Endereço"
                  onChange={(event) =>
                    setValue(
                      'addressOfPayRent_physicalPerson_locatario',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  value={
                    watch().phoneNumberOfPayRent_physicalPerson_locatario || ''
                  }
                  fullWidth
                  error={
                    !!errors?.phoneNumberOfPayRent_physicalPerson_locatario
                  }
                  helperText={
                    errors?.phoneNumberOfPayRent_physicalPerson_locatario
                      ?.message || ''
                  }
                  label="Telefone"
                  onChange={(event) =>
                    setValue(
                      'phoneNumberOfPayRent_physicalPerson_locatario',
                      event.target.value
                    )
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
      {watch('civilStatus_physicalPerson_locatario') === 'casado(a)' && (
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
                    value={watch().spouseName_physicalPerson || ''}
                    fullWidth
                    error={!!errors?.spouseName_physicalPerson}
                    helperText={
                      errors?.spouseName_physicalPerson?.message || ''
                    }
                    label="Nome"
                    required
                    onChange={(event) =>
                      setValue('spouseName_physicalPerson', event.target.value)
                    }
                  />
                </Grid>
                <Grid item md={4} xs={12}>
                  <TextField
                    value={watch().spouseNationality_physicalPerson || ''}
                    fullWidth
                    error={!!errors?.spouseNationality_physicalPerson}
                    helperText={
                      errors?.spouseNationality_physicalPerson?.message || ''
                    }
                    label="Nacionalidade"
                    required
                    onChange={(event) =>
                      setValue(
                        'spouseNationality_physicalPerson',
                        event.target.value
                      )
                    }
                  />
                </Grid>

                <Grid item md={3} xs={12}>
                  <TextField
                    value={watch().spouseProfession_physicalPerson || ''}
                    fullWidth
                    error={!!errors?.spouseProfession_physicalPerson}
                    helperText={
                      errors?.spouseProfession_physicalPerson?.message || ''
                    }
                    label="Profissão"
                    required
                    onChange={(event) =>
                      setValue(
                        'spouseProfession_physicalPerson',
                        event.target.value
                      )
                    }
                  />
                </Grid>
                <Grid item md={3} xs={12}>
                  <TextField
                    value={watch().spouseRg_physicalPerson || ''}
                    fullWidth
                    error={!!errors?.spouseRg_physicalPerson}
                    helperText={errors?.spouseRg_physicalPerson?.message || ''}
                    label="RG"
                    required
                    onChange={(event) =>
                      setValue('spouseRg_physicalPerson', event.target.value)
                    }
                  />
                </Grid>
                <Grid item md={3} xs={12}>
                  <TextField
                    value={watch().spouseCpf_physicalPerson || ''}
                    fullWidth
                    error={!!errors?.spouseCpf_physicalPerson}
                    helperText={errors?.spouseCpf_physicalPerson?.message || ''}
                    label="CPF"
                    required
                    onChange={(event) =>
                      setValue('spouseCpf_physicalPerson', event.target.value)
                    }
                    InputProps={{
                      inputComponent: CpfMaskCustom as any,
                    }}
                    InputLabelProps={{ shrink: true }}
                  />
                </Grid>
                <Grid item md={3} xs={12}>
                  <TextField
                    value={watch().spouseNumberOfSons_physicalPerson || ''}
                    fullWidth
                    error={!!errors?.spouseNumberOfSons_physicalPerson}
                    helperText={
                      errors?.spouseNumberOfSons_physicalPerson?.message || ''
                    }
                    label="Número de filhos"
                    required
                    onChange={(event) =>
                      setValue(
                        'spouseNumberOfSons_physicalPerson',
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
          <CardHeader title="Emprego atual" />
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
                  value={watch().company_physicalPerson || ''}
                  fullWidth
                  error={!!errors?.company_physicalPerson}
                  helperText={errors?.company_physicalPerson?.message || ''}
                  label="Empresa"
                  required
                  onChange={(event) =>
                    setValue('company_physicalPerson', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <DatePicker
                  label="Data de Admissão"
                  value={watch().admissionDateCompany_physicalPerson || null}
                  onChange={(date) => {
                    setValue('admissionDateCompany_physicalPerson', date);
                  }}
                  renderInput={(params) => (
                    <TextField
                      fullWidth
                      required
                      {...params}
                      error={!!errors?.admissionDateCompany_physicalPerson}
                      helperText={
                        errors?.admissionDateCompany_physicalPerson?.message ||
                        ''
                      }
                    />
                  )}
                  inputFormat="dd/MM/yyyy"
                  maxDate={new Date()}
                />
              </Grid>

              <Grid item md={8} xs={12}>
                <TextField
                  value={watch().addressOfCompany_physicalPerson || ''}
                  fullWidth
                  error={!!errors?.addressOfCompany_physicalPerson}
                  helperText={
                    errors?.addressOfCompany_physicalPerson?.message || ''
                  }
                  label="Endereço"
                  required
                  onChange={(event) =>
                    setValue(
                      'addressOfCompany_physicalPerson',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={2} xs={12}>
                <TextField
                  value={watch().phoneNumberOfCompany_physicalPerson || ''}
                  fullWidth
                  error={!!errors?.phoneNumberOfCompany_physicalPerson}
                  helperText={
                    errors?.phoneNumberOfCompany_physicalPerson?.message || ''
                  }
                  label="Telefone"
                  required
                  onChange={(event) =>
                    setValue(
                      'phoneNumberOfCompany_physicalPerson',
                      event.target.value
                    )
                  }
                  InputProps={{
                    inputComponent: PhoneMaskCustom as any,
                  }}
                  InputLabelProps={{ shrink: true }}
                />
              </Grid>
              <Grid item md={2} xs={12}>
                <TextField
                  value={watch().districtOfCompany_physicalPerson || ''}
                  fullWidth
                  error={!!errors?.districtOfCompany_physicalPerson}
                  helperText={
                    errors?.districtOfCompany_physicalPerson?.message || ''
                  }
                  label="Bairro"
                  required
                  onChange={(event) =>
                    setValue(
                      'districtOfCompany_physicalPerson',
                      event.target.value
                    )
                  }
                />
              </Grid>

              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().cityOfCompany_physicalPerson || ''}
                  fullWidth
                  error={!!errors?.cityOfCompany_physicalPerson}
                  helperText={
                    errors?.cityOfCompany_physicalPerson?.message || ''
                  }
                  label="Cidade"
                  required
                  onChange={(event) =>
                    setValue('cityOfCompany_physicalPerson', event.target.value)
                  }
                />
              </Grid>
              <Grid item md={4} xs={12}>
                <TextField
                  value={watch().positionInCompany_physicalPerson || ''}
                  fullWidth
                  error={!!errors?.positionInCompany_physicalPerson}
                  helperText={
                    errors?.positionInCompany_physicalPerson?.message || ''
                  }
                  label="Cargo que ocupa"
                  required
                  onChange={(event) =>
                    setValue(
                      'positionInCompany_physicalPerson',
                      event.target.value
                    )
                  }
                />
              </Grid>
              <Grid item md={2} xs={12}>
                <TextField
                  value={watch().salary_physicalPerson || ''}
                  fullWidth
                  error={!!errors?.salary_physicalPerson}
                  helperText={errors?.salary_physicalPerson?.message || ''}
                  label="Ordenado(R$)"
                  required
                  onChange={(event) =>
                    setValue('salary_physicalPerson', event.target.value)
                  }
                  InputProps={{
                    inputComponent: MoneyMaskCustom as any,
                    startAdornment: (
                      <InputAdornment position="start">R$</InputAdornment>
                    ),
                  }}
                />
              </Grid>
              <Grid item md={2} xs={12}>
                <TextField
                  value={watch().others_physicalPerson || ''}
                  fullWidth
                  error={!!errors?.others_physicalPerson}
                  helperText={errors?.others_physicalPerson?.message || ''}
                  label="Outros($)"
                  onChange={(event) =>
                    setValue('others_physicalPerson', event.target.value)
                  }
                  InputProps={{
                    inputComponent: MoneyMaskCustom as any,
                    startAdornment: (
                      <InputAdornment position="start">R$</InputAdornment>
                    ),
                  }}
                />
              </Grid>
            </Grid>
          </CardContent>
        </Card>
      </Grid>
    </>
  );
}

export default PhysicalPerson;
