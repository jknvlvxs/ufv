import { Box } from '@mui/material';
import { styled } from '@mui/material/styles';
import { NavLink } from 'react-router-dom';
import Icon from 'src/assets/Icon';
import HeaderUserbox from './Userbox';

const HeaderWrapper = styled(Box)(
  ({ theme }) => `
        height: ${theme.header.height};
        color: ${theme.header.textColor};
        padding: ${theme.spacing(0, 2)};
        right: 0;
        z-index: 5;
        background-color: ${theme.header.background};
        box-shadow: ${theme.header.boxShadow};
        position: fixed;
        justify-content: space-between;
        width: 100%;
        @media (min-width: ${theme.breakpoints.values.lg}px) {
            left: 0;
            width: auto;
        }
`
);

function Header() {
  return (
    <HeaderWrapper display="flex" alignItems="center">
      <Box
        display="flex"
        alignItems="center"
        component={NavLink}
        to="/"
        // children={<Icon width="80%" styles={{marginLeft: "300"}}/>}
      />
      <Box display="flex" alignItems="center" children={<HeaderUserbox />} />
    </HeaderWrapper>
  );
}

export default Header;
