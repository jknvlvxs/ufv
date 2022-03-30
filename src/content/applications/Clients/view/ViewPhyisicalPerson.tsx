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

function ViewPhysicalPerson(client) {
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
            </Box>
          </Box>
          <Divider />
          <CardContent sx={{ p: 4 }}>
            <Typography variant="subtitle2">
              <Grid container spacing={0}>
                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Nome completo:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.name_physicalPerson_locatario}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Nome do pai:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.fatherName_physicalPerson_locatario}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Nome da mãe:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.motherName_physicalPerson_locatario} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Endereço:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.address_physicalPerson_locatario}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Tempo de residência:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.residenceTime_physicalPerson_locatario} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Bairro:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.district_physicalPerson_locatario} </b>
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
                        value={client.cep_physicalPerson_locatario}
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
                    <b> {client.city_physicalPerson_locatario} </b>
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
                        value={client.homePhone_physicalPerson_locatario}
                        displayType={'text'}
                        format={
                          client.homePhone_physicalPerson_locatario?.length > 10
                            ? '(##) # ####-####'
                            : '(##) ####-####'
                        }
                      />
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Email:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.email_physicalPerson_locatario} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Celular:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      <NumberFormat
                        value={client.phoneNumber_physicalPerson_locatario}
                        displayType={'text'}
                        format={
                          client.phoneNumber_physicalPerson_locatario?.length >
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
                    Nacionalidade:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.nationality_physicalPerson_locatario} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Natural de:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.naturalFrom_physicalPerson_locatario} </b>
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
                        client.dateOfBirth_physicalPerson_locatario
                      ).format('DD/MM/YYYY')}
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Estado civil:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.civilStatus_physicalPerson_locatario} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    RG:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.rg_physicalPerson_locatario} </b>
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
                        value={client.cpf_physicalPerson_locatario}
                        displayType={'text'}
                        format="###.###.###-##"
                      />
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
                    <b> {client.profession_physicalPerson_locatario} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Nome da imobiliária ou proprietário a quem você paga o
                    aluguel:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.nameOfPayRent_physicalPerson_locatario} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Valor:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      <NumberFormat
                        value={client.rentValue_physicalPerson_locatario}
                        displayType="text"
                        thousandSeparator="."
                        decimalSeparator=","
                        decimalScale={2}
                        fixedDecimalScale={true}
                        prefix="R$"
                      />
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Endereço:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.addressOfPayRent_physicalPerson_locatario} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Telefone:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      <NumberFormat
                        value={
                          client.phoneNumberOfPayRent_physicalPerson_locatario
                        }
                        displayType={'text'}
                        format={
                          client.phoneNumberOfPayRent_physicalPerson_locatario
                            ?.length > 10
                            ? '(##) # ####-####'
                            : '(##) ####-####'
                        }
                      />
                    </b>
                  </Text>
                </Grid>
              </Grid>
            </Typography>
          </CardContent>
        </Card>
      </Grid>
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
                Emprego atual
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
                    <b> {client.company_physicalPerson} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Data de admissão:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      {moment(
                        client.admissionDateCompany_physicalPerson
                      ).format('DD/MM/YYYY')}
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Endereço:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.addressOfCompany_physicalPerson} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Telefone:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      <NumberFormat
                        value={client.phoneNumberOfCompany_physicalPerson}
                        displayType={'text'}
                        format={
                          client.phoneNumberOfCompany_physicalPerson?.length >
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
                    Bairro:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.districtOfCompany_physicalPerson} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Cidade:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.cityOfCompany_physicalPerson} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Cargo que ocupa:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.positionInCompany_physicalPerson} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Ordenado:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      <NumberFormat
                        value={client.salary_physicalPerson}
                        displayType="text"
                        thousandSeparator="."
                        decimalSeparator=","
                        decimalScale={2}
                        fixedDecimalScale={true}
                        prefix="R$"
                      />
                    </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Outros:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>
                      <NumberFormat
                        value={client.others_physicalPerson}
                        displayType={'text'}
                        thousandSeparator="."
                        decimalSeparator=","
                        decimalScale={2}
                        fixedDecimalScale={true}
                        prefix="R$"
                      />
                    </b>
                  </Text>
                </Grid>
              </Grid>
            </Typography>
          </CardContent>
        </Card>
      </Grid>

      {(client.civilStatus_physicalPerson_locatario !== 'casado(a)' && (
        <></>
      )) || (
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
                    Cônjuge
                  </Typography>
                </Box>
              </Box>
              <Divider />
              <CardContent sx={{ p: 4 }}>
                <Typography variant="subtitle2">
                  <Grid container spacing={0}>
                    <Grid
                      item
                      xs={12}
                      sm={4}
                      md={3}
                      textAlign={{ sm: 'right' }}
                    >
                      <Box pr={3} pb={2}>
                        Nome:
                      </Box>
                    </Grid>
                    <Grid item xs={12} sm={8} md={9}>
                      <Text color="black">
                        <b> {client.spouseName_physicalPerson} </b>
                      </Text>
                    </Grid>

                    <Grid
                      item
                      xs={12}
                      sm={4}
                      md={3}
                      textAlign={{ sm: 'right' }}
                    >
                      <Box pr={3} pb={2}>
                        Nacionalidade:
                      </Box>
                    </Grid>
                    <Grid item xs={12} sm={8} md={9}>
                      <Text color="black">
                        <b> {client.spouseNationality_physicalPerson} </b>
                      </Text>
                    </Grid>

                    <Grid
                      item
                      xs={12}
                      sm={4}
                      md={3}
                      textAlign={{ sm: 'right' }}
                    >
                      <Box pr={3} pb={2}>
                        Profissão:
                      </Box>
                    </Grid>
                    <Grid item xs={12} sm={8} md={9}>
                      <Text color="black">
                        <b> {client.spouseProfession_physicalPerson} </b>
                      </Text>
                    </Grid>

                    <Grid
                      item
                      xs={12}
                      sm={4}
                      md={3}
                      textAlign={{ sm: 'right' }}
                    >
                      <Box pr={3} pb={2}>
                        RG:
                      </Box>
                    </Grid>
                    <Grid item xs={12} sm={8} md={9}>
                      <Text color="black">
                        <b> {client.spouseRg_physicalPerson} </b>
                      </Text>
                    </Grid>

                    <Grid
                      item
                      xs={12}
                      sm={4}
                      md={3}
                      textAlign={{ sm: 'right' }}
                    >
                      <Box pr={3} pb={2}>
                        CPF:
                      </Box>
                    </Grid>
                    <Grid item xs={12} sm={8} md={9}>
                      <Text color="black">
                        <b>
                          <NumberFormat
                            value={client.spouseCpf_physicalPerson}
                            displayType={'text'}
                            format="###-###-###-##"
                          />
                        </b>
                      </Text>
                    </Grid>

                    <Grid
                      item
                      xs={12}
                      sm={4}
                      md={3}
                      textAlign={{ sm: 'right' }}
                    >
                      <Box pr={3} pb={2}>
                        Número de filhos:
                      </Box>
                    </Grid>
                    <Grid item xs={12} sm={8} md={9}>
                      <Text color="black">
                        <b> {client.spouseNumberOfSons_physicalPerson} </b>
                      </Text>
                    </Grid>
                  </Grid>
                </Typography>
              </CardContent>
            </Card>
          </Grid>
        </>
      )}
    </>
  );
}

export default ViewPhysicalPerson;
