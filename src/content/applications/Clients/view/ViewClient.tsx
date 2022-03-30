import {
  Grid,
  Typography,
  CardContent,
  Card,
  Box,
  Divider,
  Button,
} from '@mui/material';
import FileDownloadTwoToneIcon from '@mui/icons-material/FileDownloadTwoTone';

import Text from 'src/components/Text';
import ViewPhysicalPerson from './ViewPhyisicalPerson';
import ViewJuridicalPerson from './ViewJuridicalPerson';
import ViewGuarantor from './ViewGuarantor';
import moment from 'moment';
import { default as NumberFormat } from 'react-number-format';
import References from './References';
import { download } from 'src/services/client';

function ViewClient(client) {
  const handleDownload = async (fileName) => {
    let parts = fileName.split('.');
    const extension = parts.pop();
    let type = '';
    switch (extension) {
      case 'jpg':
      case 'jpeg':
        type = 'image/jpeg';
        break;

      case 'png':
        type = 'image/png';
        break;
      case 'gif':
        type = 'image/gif';
        break;
      case 'pdf':
        type = 'application/pdf';
        break;
      default:
        alert('Ocorreu um erro');
    }

    const data = await download(fileName);
    const file = new File([data], fileName, {
      type: type,
    });
    const url = URL.createObjectURL(file);
    window.open(url, '_blank');
  };
  return (
    <Grid container spacing={3}>
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
                Dados do imóvel
              </Typography>
            </Box>
          </Box>
          <Divider />
          <CardContent sx={{ p: 4 }}>
            <Typography variant="subtitle2">
              <Grid container spacing={0}>
                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Finalidade:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.goal}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Código do imóvel:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Text color="black">
                    <b>{client.propertyCode}</b>
                  </Text>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Endereço do imóvel:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Box sx={{ maxWidth: { xs: 'auto', sm: 300 } }}>
                    <Text color="black">
                      <b>{client.propertyAddress}</b>
                    </Text>
                  </Box>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Bairro:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Box sx={{ maxWidth: { xs: 'auto', sm: 300 } }}>
                    <Text color="black">
                      <b>{client.district}</b>
                    </Text>
                  </Box>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Nome do proprietário:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Box sx={{ maxWidth: { xs: 'auto', sm: 300 } }}>
                    <Text color="black">
                      <b>{client.ownerName}</b>
                    </Text>
                  </Box>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Valor do aluguel:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Box sx={{ maxWidth: { xs: 'auto', sm: 300 } }}>
                    <Text color="black">
                      <b>
                        <NumberFormat
                          value={client.rentValue}
                          displayType="text"
                          thousandSeparator="."
                          decimalSeparator=","
                          decimalScale={2}
                          fixedDecimalScale={true}
                          prefix="R$"
                        />
                      </b>
                    </Text>
                  </Box>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Prazo:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Box sx={{ maxWidth: { xs: 'auto', sm: 300 } }}>
                    <Text color="black">
                      <b>{client.deadline}</b>
                    </Text>
                  </Box>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Reajuste:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Box sx={{ maxWidth: { xs: 'auto', sm: 300 } }}>
                    <Text color="black">
                      <b>
                        <NumberFormat
                          value={client.readjustment}
                          displayType="text"
                          thousandSeparator="."
                          decimalSeparator=","
                          decimalScale={2}
                          fixedDecimalScale={true}
                          prefix="R$"
                        />
                      </b>
                    </Text>
                  </Box>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Data de início:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Box sx={{ maxWidth: { xs: 'auto', sm: 300 } }}>
                    <Text color="black">
                      <b>{moment(client.startDate).format('DD/MM/YYYY')}</b>
                    </Text>
                  </Box>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Data de término:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Box sx={{ maxWidth: { xs: 'auto', sm: 300 } }}>
                    <Text color="black">
                      <b>{moment(client.finishDate).format('DD/MM/YYYY')}</b>
                    </Text>
                  </Box>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Observações:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Box sx={{ maxWidth: { xs: 'auto', sm: 300 } }}>
                    <Text color="black">
                      <b>{client.comments}</b>
                    </Text>
                  </Box>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Xerox do RG e CPF:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Box sx={{ maxWidth: { xs: 'auto', sm: 300 } }}>
                    <Button
                      variant="text"
                      onClick={() => {
                        handleDownload(client.documentFile);
                      }}
                      color="inherit"
                    >
                      <FileDownloadTwoToneIcon color="secondary"></FileDownloadTwoToneIcon>
                      <b>Baixe o arquivo</b>
                    </Button>
                  </Box>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Comprovante de residência:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Box sx={{ maxWidth: { xs: 'auto', sm: 300 } }}>
                    <Button
                      variant="text"
                      color="inherit"
                      onClick={() => {
                        handleDownload(client.receiptAddress);
                      }}
                    >
                      <FileDownloadTwoToneIcon color="secondary"></FileDownloadTwoToneIcon>
                      <b>Baixe o arquivo</b>
                    </Button>
                  </Box>
                </Grid>

                <Grid item xs={12} sm={4} md={3} textAlign={{ sm: 'right' }}>
                  <Box pr={3} pb={2}>
                    Comprovante de renda:
                  </Box>
                </Grid>
                <Grid item xs={12} sm={8} md={9}>
                  <Box sx={{ maxWidth: { xs: 'auto', sm: 300 } }}>
                    <Button
                      variant="text"
                      onClick={() => {
                        handleDownload(client.receiptIncome);
                      }}
                      color="inherit"
                    >
                      <FileDownloadTwoToneIcon color="secondary"></FileDownloadTwoToneIcon>
                      <b> Baixe o arquivo</b>
                    </Button>
                  </Box>
                </Grid>
              </Grid>
            </Typography>
          </CardContent>
        </Card>
      </Grid>

      {(client.personValue === 'physical' && (
        <ViewPhysicalPerson {...client} />
      )) || <ViewJuridicalPerson {...client} />}

      <References {...client} />

      {client.guarantorValue === 'yes' && <ViewGuarantor {...client} />}
    </Grid>
  );
}

export default ViewClient;
