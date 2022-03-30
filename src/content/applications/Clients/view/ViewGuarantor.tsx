import {
  Grid,
  Typography,
  CardContent,
  Card,
  Box,
  Divider,
} from '@mui/material';
import { default as NumberFormat } from 'react-number-format';
import moment from 'moment';
import Text from 'src/components/Text';

function ViewGuarantor(client) {
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
                1º Fiador
              </Typography>
            </Box>
          </Box>
          <Divider />
          <CardContent sx={{ p: 4 }}>
            <Typography variant="subtitle2">
              <Grid container spacing={0}>
                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Nome:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.guarantorName}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Endereço:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.guarantorAddress}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Tempo de residência:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.guarantorResidentialTime} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Bairro:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.guarantorDistrict} </b>
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
                        value={client.guarantorCep}
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
                    <b> {client.guarantorCity} </b>
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
                        value={client.guarantorResidentialPhone}
                        displayType={'text'}
                        format={
                          client.guarantorResidentialPhone?.length > 10
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
                    <b> {client.guarantorEmail} </b>
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
                        value={client.guarantorCellPhone}
                        displayType={'text'}
                        format={
                          client.guarantorCellPhone?.length > 10
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
                    <b> {client.guarantorNationality} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Natural de:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.guarantorNaturalFrom} </b>
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
                      {moment(client.guarantorDateOfBirth).format('DD/MM/YYYY')}
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
                    <b> {client.guarantorCivilStatus} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    RG:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.guarantorRg} </b>
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
                        value={client.guarantorCpf}
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
                    <b> {client.guarantorProfession} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Nome do pai:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.guarantorFatherName}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Nome da mãe:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.guarantorMotherName} </b>
                  </Text>
                </Grid>
              </Grid>
            </Typography>
          </CardContent>
        </Card>
      </Grid>
      {(client.guarantorCivilStatus !== 'casado(a)' && <></>) || (
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
                        <b> {client.guarantorSpouseName} </b>
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
                        <b> {client.guarantorSpouseNationality} </b>
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
                        <b> {client.guarantorSpouseProfession} </b>
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
                        <b> {client.guarantorSpouseRg} </b>
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
                            value={client.guarantorSpouseCpf}
                            displayType={'text'}
                            format="###.###.###-##"
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
                        <b> {client.guarantorSpouseNumberOfSons} </b>
                      </Text>
                    </Grid>
                  </Grid>
                </Typography>
              </CardContent>
            </Card>
          </Grid>
        </>
      )}

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
                2º Fiador
              </Typography>
            </Box>
          </Box>
          <Divider />
          <CardContent sx={{ p: 4 }}>
            <Typography variant="subtitle2">
              <Grid container spacing={0}>
                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Nome:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.guarantorName_2}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Endereço:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.guarantorAddress_2}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Tempo de residência:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.guarantorResidentialTime_2} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Bairro:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.guarantorDistrict_2} </b>
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
                        value={client.guarantorCep_2}
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
                    <b> {client.guarantorCity_2} </b>
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
                        value={client.guarantorResidentialPhone_2}
                        displayType={'text'}
                        format={
                          client.guarantorResidentialPhone_2?.length > 10
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
                    <b> {client.guarantorEmail_2} </b>
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
                        value={client.guarantorCellPhone_2}
                        displayType={'text'}
                        format={
                          client.guarantorCellPhone_2?.length > 10
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
                    <b> {client.guarantorNationality_2} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Natural de:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.guarantorNaturalFrom_2} </b>
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
                      {moment(client.guarantorDateOfBirth_2).format(
                        'DD/MM/YYYY'
                      )}
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
                    <b> {client.guarantorCivilStatus_2} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    RG:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.guarantorRg_2} </b>
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
                        value={client.guarantorCpf_2}
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
                    <b> {client.guarantorProfession_2} </b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Nome do pai:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.guarantorFatherName_2}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Nome da mãe:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b> {client.guarantorMotherName_2} </b>
                  </Text>
                </Grid>
              </Grid>
            </Typography>
          </CardContent>
        </Card>
      </Grid>

      {(client.guarantorCivilStatus_2 !== 'casado(a)' && <></>) || (
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
                        <b> {client.guarantorSpouseName_2} </b>
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
                        <b> {client.guarantorSpouseNationality_2} </b>
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
                        <b> {client.guarantorSpouseProfession_2} </b>
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
                        <b> {client.guarantorSpouseRg_2} </b>
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
                            value={client.guarantorSpouseCpf_2}
                            displayType={'text'}
                            format="###.###.###-##"
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
                        <b> {client.guarantorSpouseNumberOfSons_2} </b>
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

export default ViewGuarantor;
