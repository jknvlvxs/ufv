import {
  Grid,
  Typography,
  CardContent,
  Card,
  Box,
  Divider,
} from '@mui/material';

import Text from 'src/components/Text';
import moment from 'moment';
import { default as NumberFormat } from 'react-number-format';

function ViewJuridicalPerson(client) {
  return (
    <>
      <Grid item xs={12}>
        <Card>
          <Box
            p={3}
            display="flex"
            alignItems="center"
            justifyContent="space-between"
          >
            <Box>
              <Typography variant="h4" gutterBottom>
                Locatário
              </Typography>
              <Typography variant="subtitle2">
                Manage details related to your account
              </Typography>
            </Box>
          </Box>
          <Divider />
          <CardContent sx={{ p: 4 }}>
            <Typography variant="subtitle2">
              <Grid container spacing={0}>
                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Empresa:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.companyName_juridicalPerson_locatario}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Representante:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      {client.companyRepresentative_juridicalPerson_locatario}
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Profissão:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.profession_juridicalPerson_locatario} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Endereço:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.address_juridicalPerson_locatario}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Tempo de residência:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.residenceTime_juridicalPerson_locatario} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Bairro:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.district_juridicalPerson_locatario} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    CEP:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      <NumberFormat
                        value={client.cep_juridicalPerson_locatario}
                        displayType={'text'}
                        format="#####-###"
                      />
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Cidade:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.city_juridicalPerson_locatario} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Estado civil:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.civilStatus_juridicalPerson_locatario} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    CPF:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      <NumberFormat
                        value={client.cpf_juridicalPerson_locatario}
                        displayType={'text'}
                        format="###.###.###-##"
                      />
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    RG:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.rg_juridicalPerson_locatario} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Data de nascimento:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      {moment(
                        client.dateOfBirth_juridicalPerson_locatario
                      ).format('DD/MM/YYYY')}
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Telefone celular:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      <NumberFormat
                        value={client.phoneNumber_juridicalPerson_locatario}
                        displayType={'text'}
                        format={
                          client.phoneNumber_juridicalPerson_locatario?.length >
                          10
                            ? '(##) # ####-####'
                            : '(##) ####-####'
                        }
                      />
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    CNPJ:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      <NumberFormat
                        value={client.cnpj_juridicalPerson_locatario}
                        displayType={'text'}
                        format="##.###.###/####-##"
                      />
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    INSC. Estadual:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.stateRegistration_juridicalPerson_locatario}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Telefone comercial:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      <NumberFormat
                        value={
                          client.phoneNumberCommercial_juridicalPerson_locatario
                        }
                        displayType={'text'}
                        format={
                          client.phoneNumberCommercial_juridicalPerson_locatario
                            ?.length > 10
                            ? '(##) # ####-####'
                            : '(##) ####-####'
                        }
                      />
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Ramo de atividade da empresa:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      {client.branchOfActivityCompany_juridicalPerson_locatario}
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Tempo de atividade da empresa:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      {client.timeOfActivityCompany_juridicalPerson_locatario}
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Endereço anterior da empresa:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.previousAddress_juridicalPerson_locatario}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Telefone residencial:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      <NumberFormat
                        value={
                          client.phoneResidential_juridicalPerson_locatario
                        }
                        displayType={'text'}
                        format={
                          client.phoneResidential_juridicalPerson_locatario
                            ?.length > 10
                            ? '(##) # ####-####'
                            : '(##) ####-####'
                        }
                      />
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Bairro:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.companyDistrict_juridicalPerson_locatario}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    CEP:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      <NumberFormat
                        value={client.companyCep_juridicalPerson_locatario}
                        displayType={'text'}
                        format="#####-###"
                      />
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Cidade:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.companyCity_juridicalPerson_locatario}</b>
                  </Text>
                </Grid>
              </Grid>
            </Typography>
          </CardContent>
        </Card>
      </Grid>
    </>
  );
}

export default ViewJuridicalPerson;
